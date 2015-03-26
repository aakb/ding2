<?php

/**
 * @file
 * Test loan provider functions.
 */

require_once "ProviderTestCase.php";
require_once 'includes/classes/FBS.php';
require_once dirname(__DIR__) . '/vendor/autoload.php';

if (!function_exists('ding_provider_build_entity_id')) {
  /**
   * Loan list calls this, mock it.
   */
  function ding_provider_build_entity_id($id, $agency = '') {
    return $id . ($agency ? ":" . $agency : '');
  }
}


if (!function_exists('t')) {
  /**
   * DingProviderLoan::__construct() calls this, mock it.
   */
  function t($str) {
    return $str;
  }
}

/**
 * Test loan provider functions.
 */
class LoanProviderTest extends ProviderTestCase {

  /**
   * Test loan list.
   */
  public function testList() {
    $this->provider = 'loan';
    // Define DingEntity.
    $this->requireDing('ding_entity', 'ding_entity.module');
    // Define DingProviderUserException.
    $this->requireDing('ding_provider', 'ding_provider.exceptions.inc');
    // Define DingProviderLoan.
    $this->requireDing('ding_provider', 'ding_provider.loan.inc');

    $json_responses = array(
      // TCLL1: Patron has no loans 
      new Reply(
        array()
      ),

      // TCLL2: Patron has a renewable loan
      new Reply(
        array(
          // Array of...
          array(
            // Loan.
            'isRenewable' => TRUE,
            'loanDetails' => array(
              // LoanDetails.
              'recordId' => 'RECID30',
              'dueDate' => 'DUEDATE30',
              'loanDate' => 'LOANDATE30',
              'materialItemNumber' => 'ITEMNUM30',
              'loanId' => 30,
            ),
            'renewalStatusList' => array(),
          ),
        )
      ),

      // TCLL3: Patron has a loan that has reached max limit of renewables
      new Reply(
        array(
          // Array of...
          array(
            // Loan.
            'isRenewable' => FALSE,
            'loanDetails' => array(
              // LoanDetails.
              'recordId' => 'RECID31',
              'dueDate' => 'DUEDATE31',
              'loanDate' => 'LOANDATE31',
              'materialItemNumber' => 'ITEMNUM31',
              'loanId' => 31,
            ),
            'renewalStatusList' => array(
              'deniedMaxRenewalsReached',
            ),
          ),
        )
      ),

      // TCLL4: Patron with multiple loans, both renewable and not
      new Reply(
        array(
          // Array of...
          array(
            // Loan.
            'isRenewable' => TRUE,
            'loanDetails' => array(
              // LoanDetails.
              'recordId' => 'RECID32',
              'dueDate' => 'DUEDATE32',
              'loanDate' => 'LOANDATE32',
              'materialItemNumber' => 'ITEMNUM32',
              'loanId' => 32,
            ),
            'renewalStatusList' => array(),
          ),
          array(
            // Loan.
            'isRenewable' => TRUE,
            'loanDetails' => array(
              // LoanDetails.
              'recordId' => 'RECID33',
              'dueDate' => 'DUEDATE33',
              'loanDate' => 'LOANDATE33',
              'materialItemNumber' => 'ITEMNUM33',
              'loanId' => 33,
            ),
            'renewalStatusList' => array(),
          ),
          array(
            // Loan.
            'isRenewable' => FALSE,
            'loanDetails' => array(
              // LoanDetails.
              'recordId' => 'RECID34',
              'dueDate' => 'DUEDATE34',
              'loanDate' => 'LOANDATE34',
              'materialItemNumber' => 'ITEMNUM34',
              'loanId' => 34,
            ),
            'renewalStatusList' => array(
              'deniedReserved',
            ),
          ),
          array(
            // Loan.
            'isRenewable' => FALSE,
            'loanDetails' => array(
              // LoanDetails.
              'recordId' => 'RECID35',
              'dueDate' => 'DUEDATE35',
              'loanDate' => 'LOANDATE35',
              'materialItemNumber' => 'ITEMNUM35',
              'loanId' => 35,
            ),
            'renewalStatusList' => array(
              'deniedOtherReason',
            ),
          ),
        )
      ),
    );
    $httpclient = $this->getHttpClient($json_responses);

    // Run through tests.
    $fbs = fbs_service('1234', '', $httpclient, NULL, TRUE);

    // TCLL1: Loaner with no loans
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PATID10',
      ),
    );

    // Check success.
    $res = $this->providerInvoke('list', $user);
    $expected = array();
    $this->assertEquals($expected, $res);


    // TCLL2: Loaner with renewable loan
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PATID11',
      ),
    );

    $res = $this->providerInvoke('list', $user);
    $expected = array(
      30 => new DingProviderLoan(30, array(
        'ding_entity_id' => 'RECID30',
        'loan_date' => 'LOANDATE30',
        'expiry' => 'DUEDATE30',
        'renewable' => TRUE,
        'materials_number' => 'ITEMNUM30',
      )),
    );
    $this->assertEquals($expected, $res);

    // TCLL3: Loaner with non-renewable loan (max reached)
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PATID12',
      ),
    );

    $res = $this->providerInvoke('list', $user);
    $expected = array(
      31 => new DingProviderLoan(31, array(
        'ding_entity_id' => 'RECID31',
        'loan_date' => 'LOANDATE31',
        'expiry' => 'DUEDATE31',
        'renewable' => FALSE,
        'materials_number' => 'ITEMNUM31',
      )),
    );
    $this->assertEquals($expected, $res);

    // TCLL4: Loaner with renewable loan
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PATID13',
      ),
    );

    $res = $this->providerInvoke('list', $user);
    $expected = array(
      32 => new DingProviderLoan(32, array(
        'ding_entity_id' => 'RECID32',
        'loan_date' => 'LOANDATE32',
        'expiry' => 'DUEDATE32',
        'renewable' => TRUE,
        'materials_number' => 'ITEMNUM32',
      )),

      33 => new DingProviderLoan(33, array(
        'ding_entity_id' => 'RECID33',
        'loan_date' => 'LOANDATE33',
        'expiry' => 'DUEDATE33',
        'renewable' => TRUE,
        'materials_number' => 'ITEMNUM33',
      )),

       34 => new DingProviderLoan(34, array(
        'ding_entity_id' => 'RECID34',
        'loan_date' => 'LOANDATE34',
        'expiry' => 'DUEDATE34',
        'renewable' => FALSE,
        'materials_number' => 'ITEMNUM34',
      )),

      35 => new DingProviderLoan(35, array(
        'ding_entity_id' => 'RECID35',
        'loan_date' => 'LOANDATE35',
        'expiry' => 'DUEDATE35',
        'renewable' => FALSE,
        'materials_number' => 'ITEMNUM35',
      )),
    );
    $this->assertEquals($expected, $res);
  }

  /**
   * Test loan renew.
   */
  public function testRenew() {
    $this->provider = 'loan';
    // Define DingEntity.
    $this->requireDing('ding_entity', 'ding_entity.module');
    // Define DingProviderUserException.
    $this->requireDing('ding_provider', 'ding_provider.exceptions.inc');
    // Define DingProviderLoan.
    $this->requireDing('ding_provider', 'ding_provider.loan.inc');

    $json_responses = array(
      new Reply(
        array(
          // Array of...
          array(
            // RenewedLoan.
            'loanDetails' => array(
              // LoanDetails.
              'recordId'  => 'x',
              'dueDate' => 'x',
              'loanDate' => 'x',
              'materialItemNumber' => 'x',
              'loanId' => '1',
            ),
            'renewalStatus' => array(
              'renewed',
            ),
          ),
          array(
            // RenewedLoan.
            'loanDetails' => array(
              // LoanDetails.
              'recordId'  => 'x',
              'dueDate' => 'x',
              'loanDate' => 'x',
              'materialItemNumber' => 'x',
              'loanId' => '2',
            ),
            'renewalStatus' => array(
              'deniedReserved',
            ),
          ),
          array(
            // RenewedLoan.
            'loanDetails' => array(
              // LoanDetails.
              'recordId'  => 'x',
              'dueDate' => 'x',
              'loanDate' => 'x',
              'materialItemNumber' => 'x',
              'loanId' => '3',
            ),
            'renewalStatus' => array(
              'deniedOtherReason',
            ),
          ),
        )
      ),
    );
    $httpclient = $this->getHttpClient($json_responses);

    // Run through tests.
    $fbs = fbs_service('1234', '', $httpclient, NULL, TRUE);


    // TCLR1: Patron renews empty list of loans 
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PAT14',
      ),
    );

    // Check success.
    $res = $this->providerInvoke('renew', $user, array(1, 2, 3));
    $expected = array(
      1 => DingProviderLoan::STATUS_RENEWED,
      2 => DingProviderLoan::STATUS_NOT_RENEWED,
      3 => DingProviderLoan::STATUS_NOT_RENEWED,
    );
    $this->assertEquals($expected, $res);


    // TCLR2: Patron renews loan (* OBS STATE CHANGES) 
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PAT14',
      ),
    );

    // Check success.
    $res = $this->providerInvoke('renew', $user, array(1, 2, 3));
    $expected = array(
      1 => DingProviderLoan::STATUS_RENEWED,
      2 => DingProviderLoan::STATUS_NOT_RENEWED,
      3 => DingProviderLoan::STATUS_NOT_RENEWED,
    );
    $this->assertEquals($expected, $res);


    // TCLR3: Patron tries to renew un-renewable loan 
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PAT14',
      ),
    );

    // Check success.
    $res = $this->providerInvoke('renew', $user, array(1, 2, 3));
    $expected = array(
      1 => DingProviderLoan::STATUS_RENEWED,
      2 => DingProviderLoan::STATUS_NOT_RENEWED,
      3 => DingProviderLoan::STATUS_NOT_RENEWED,
    );
    $this->assertEquals($expected, $res);


    // TCLR4: Patron renews multiple loans, both renewable and not (* OBS STATE CHANGES)
    $user = (object) array(
      'creds' => array(
        'patronId' => 'PAT14',
      ),
    );

    // Check success.
    $res = $this->providerInvoke('renew', $user, array(1, 2, 3));
    $expected = array(
      1 => DingProviderLoan::STATUS_RENEWED,
      2 => DingProviderLoan::STATUS_NOT_RENEWED,
      3 => DingProviderLoan::STATUS_NOT_RENEWED,
    );
    $this->assertEquals($expected, $res);


  }

}
