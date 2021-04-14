<?php

/**
 * Implements hook_form().
 */
function aakb_writing_competition_admin($form, &$form_state) {
  $form = [];

  $form['aakb_writing_competition'] = [
    '#type' => 'fieldset',
    '#title' => 'Configuration',
    '#tree' => TRUE,
  ];

  $defaults = _aakb_writing_competition_get_config();

  $form['aakb_writing_competition']['parent'] = [
    '#type' => 'text_format',
    '#title' => _aakb_writing_competition_t('Parent information text'),
    '#rows' => 15,
    '#format' => $defaults['parent']['format'],
    '#default_value' => $defaults['parent']['value'],
  ];

  $form['aakb_writing_competition']['teacher'] = [
    '#type' => 'text_format',
    '#title' => _aakb_writing_competition_t('Teacher information text'),
    '#rows' => 15,
    '#format' => $defaults['teacher']['format'],
    '#default_value' => $defaults['teacher']['value'],
  ];

  return system_settings_form($form);
}


function aakb_writing_competition_export($form, &$form_state) {
  return system_settings_form($form);
}
