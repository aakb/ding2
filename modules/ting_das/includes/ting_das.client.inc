<?php
/**
 * @file
 *
 */

/**
 * Class TingDasCopyRequest.
 */
class TingDasCopyRequest {

  private $url;
  private $username;
  private $password;

  private $pid = NULL;
  private $userLoanerId = NULL;
  private $userName = NULL;
  private $mail = NULL;
  private $userInterestDate = NULL;
  private $pickupAgencyId = NULL;
  private $agencyId = NULL;
  private $publicationTitle = NULL;
  private $publicationDateOfComponent = NULL;
  private $publicationYearOfComponent = NULL;
  private $issueOfComponent = NULL;
  private $volumeOfComponent = NULL;
  private $pagesOfComponent = NULL;

  /**
   * TingDasCopyRequest constructor.
   *
   * @param string $url
   *   The service endpoint for digital article service.
   * @param string $username
   *   The username to login with.
   * @param string $password
   *   The password to login with.
   */
  public function __construct(string $url, string $username, string $password) {
    $this->url = $url;
    $this->username = $username;
    $this->password = $password;
  }

  /**
   * Set date well id.
   *
   * @param string $pid
   *   The date well id for the material requested.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setPid(string $pid) {
    $this->pid = $pid;
    return $this;
  }

  /**
   * The data well id.
   *
   * @return string|null
   *   The data well pid if set else NULL.
   */
  public function getPid() {
    return $this->pid;
  }

  /**
   * Set the users loaner id.
   *
   * @param string $userLoanerId
   *   The users loaner id (borrow id/CPR).
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setUserLoanerId(string $userLoanerId) {
    $this->userLoanerId = $userLoanerId;
    return $this;
  }

  /**
   * Get the user loaner id.
   *
   * @return string|null
   *   The loaner id or null if not set.
   */
  public function getUserLoanerId() {
    return $this->userLoanerId;
  }

  /**
   * Set the username (full name of the user).
   *
   * @param string $userName
   *   The users full name.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setUserName(string $userName) {
    $this->userName = $userName;
    return $this;
  }

  /**
   * Get the users full name.
   *
   * @return string|null
   *   The users full name.
   */
  public function getUserName() {
    return $this->userName;
  }

  /**
   * Set the users e-mail-address.
   *
   * @param string $mail
   *   The users e-mail-address.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setUserMail(string $mail) {
    $this->mail = $mail;
    return $this;
  }

  /**
   * Get the users e-mail-address.
   *
   * @return string|null
   *   The users e-mail-address.
   */
  public function getUserMail() {
    return $this->mail;
  }

  /**
   * The interest date for the user.
   *
   * The date until the user is not longer interested in getting the material.
   *
   * @param string $userInterestDate
   *   The users interest date.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setUserInterestDate(string $userInterestDate) {
    $this->userInterestDate = $userInterestDate;
    return $this;
  }

  /**
   * Get the users interest date.
   *
   * @return string|null
   *   The users interest date.
   */
  public function getUserInterestDate() {
    return $this->userInterestDate;
  }

  /**
   * Set the agency id for pickup.
   *
   * @Note: Not sure why this exists as all articles are sent by mail to the
   *        end user.
   *
   * @param string $pickupAgencyId
   *   The pickup agency id.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setPickupAgencyId(string $pickupAgencyId) {
    $this->pickupAgencyId = $pickupAgencyId;
    return $this;
  }

  /**
   * Get pickup agency id.
   *
   * @return string|null
   *   The pickup agency id.
   */
  public function getPickupAgencyId() {
    return $this->pickupAgencyId;
  }

  /**
   * Set agency id.
   *
   * @param string $agencyId
   *   The agency id.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setAgencyId(string $agencyId) {
    $this->agencyId = $agencyId;
    return $this;
  }

  /**
   * Get agency id.
   *
   * @return string|null
   *   The agency id.
   */
  public function getAgencyId() {
    return $this->agencyId;
  }

  /**
   * The title of the publication.
   *
   * @param string $publicationTitle
   *   The publications title.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setPublicationTitle(string $publicationTitle) {
    $this->publicationTitle = $publicationTitle;
    return $this;
  }

  /**
   * Get article title.
   *
   * @return string|null
   *   The article title.
   */
  public function getPublicationTitle() {
    return $this->publicationTitle;
  }

  /**
   * Set the date of publication.
   *
   * @param string $publicationDateOfComponent
   *   Article publication date.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setPublicationDateOfComponent(string $publicationDateOfComponent) {
    $this->publicationDateOfComponent = $publicationDateOfComponent;
    return $this;
  }

  /**
   * Get article date.
   *
   * @return string|null
   *   The article date.
   */
  public function getPublicationDateOfComponent() {
    return $this->publicationDateOfComponent;
  }

  /**
   * Set the article year.
   *
   * @param string $publicationYearOfComponent
   *   Article year.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setPublicationYearOfComponent(string $publicationYearOfComponent) {
    $this->publicationYearOfComponent = $publicationYearOfComponent;
    return $this;
  }

  /**
   * Get the article year.
   *
   * @return string|null
   *   The article year.
   */
  public function getPublicationYearOfComponent() {
    return $this->publicationYearOfComponent;
  }

  /**
   * Set article issue number.
   *
   * @param string $issueOfComponent
   *   Article issue number.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setIssueOfComponent(string $issueOfComponent) {
    $this->issueOfComponent = $issueOfComponent;
    return $this;
  }

  public function getIssueOfComponent() {
    return $this->issueOfComponent;
  }

  /**
   * Set the the volume number.
   *
   * @param string $volumeOfComponent
   *   The article volume number.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setVolumeOfComponent(string $volumeOfComponent) {
    $this->volumeOfComponent = $volumeOfComponent;
    return $this;
  }

  /**
   * Get the article volume number.
   *
   * @return string|null
   *   The article volume number.
   */
  public function getVolumeOfComponent() {
    return $this->volumeOfComponent;
  }

  /**
   * Set the page number in the publication.
   *
   * @param string $pagesOfComponent
   *   The page number.
   *
   * @return TingDasCopyRequest
   *   The current request object.
   */
  public function setPagesOfComponent(string $pagesOfComponent) {
    $this->pagesOfComponent = $pagesOfComponent;
    return $this;
  }

  /**
   * Get the page number.
   *
   * @return string|null
   *   The page number.
   */
  public function getPagesOfComponent() {
    return $this->pagesOfComponent;
  }


  public function send() {
    // Add option to send CURL parameters with the request. This can be used
    // to send requests through a SOCKS5 ssh proxy.
    $curl_options = variable_get('ting_das_curl_options', array());

    $client = new NanoSOAPClient($this->url, array('curl' => $curl_options));
    $response = $client->call($soapAction, $soapParameters);
  }

}