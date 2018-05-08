<?php
/**
 * @file
 * Define the administration interface for the module.
 */

/**
 * Admin settings form for Ting DAS integration.
 */
function ting_das_admin_settings_form() {
  $form = array();

  $form['ting_das'] = array(
    '#type' => 'fieldset',
    '#title' => t('Digital article server'),
    '#tree' => TRUE,
  );

  $default = variable_get('ting_das', array());
  $form['ting_das']['url'] = array(
    '#type' => 'textfield',
    '#title' => t('End point'),
    '#description' => t('The service endpoint for "placeCopyRequest". E.g https://developer.statsbiblioteket.dk/elba-webservices/services/placeCopyRequest'),
    '#default_value' => $default['url'] ?? '',
  );

  // Username / password
  $form['ting_das']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('The username required to use the web-service.'),
    '#default_value' => $default['username'] ?? '',
  );

  $form['ting_das']['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('The password required to use the web-service.'),
    '#default_value' => $default['password'] ?? '',
  );
  return system_settings_form($form);
}
