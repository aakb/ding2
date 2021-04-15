<?php
/**
 * @file
 * Handle export for data.
 */

include_once __DIR__ . '/../vendor/autoload.php';

use \Box\Spout\Common\Type;
use \Box\Spout\Writer\WriterFactory;

/**
 * Implements hook_form().
 */
function aakb_writing_competition_export() {
  $num_of_rows = db_select('writing_competition', 'wc')
    ->fields('wc')
    ->countQuery()
    ->execute()
    ->fetchField();

  $link = array(
    '#theme' => 'link',
    '#text' => _aakb_writing_competition_t('Download Excel export'),
    '#path' => 'admin/config/ding/competition/export/excel',
    '#options' => array(
      'attributes' => array('class' => array('button')),
      'absolute' => TRUE,
      'html' => TRUE,
    ),
  );

  return array(
    '#theme' => 'aakb_writing_competition_export',
    '#count' => $num_of_rows,
    '#link' => $link,
  );
}

/**
 * Export data to excel.
 *
 * @throws \Box\Spout\Common\Exception\IOException
 * @throws \Box\Spout\Common\Exception\SpoutException
 * @throws \Box\Spout\Common\Exception\UnsupportedTypeException
 * @throws \Box\Spout\Writer\Exception\WriterNotOpenedException
 */
function aakb_writing_competition_export_excel() {
  $writer = WriterFactory::create(Type::XLSX);
  $writer->openToBrowser('export.xlsx');

  $rows = db_select('writing_competition', 'wc')
    ->fields('wc')
    ->orderBy('submitted')
    ->execute();

  $writer->addRow([
    'Type',
    'Name',
    'E-mail',
    'Date',
    'Writer name',
    'Grade',
    'Age',
    'Contribution',
  ]);

  foreach ($rows as $row) {
    $writer->addRow([
      $row->type,
      $row->name,
      $row->mail,
      date('c', $row->submitted),
      $row->contrib_name,
      $row->contrib_grade,
      (int) $row->contrib_age,
      $row->contribution,
    ]);
  }

  $writer->close();
}
