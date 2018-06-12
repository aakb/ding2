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
    '#default_value' => isset($default['url']) ? $default['url'] : '',
  );

  // Username / password
  $form['ting_das']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('The username required to use the web-service.'),
    '#default_value' => isset($default['username']) ? $default['username'] : '',
  );

  $form['ting_das']['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('The password required to use the web-service.'),
    '#default_value' => isset($default['password']) ? $default['password'] : '',
  );

  $types = variable_get('ting_well_types', _ting_fetch_well_types());
  $form['ting_das_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data well types'),
    '#description' => t('Ting objects defined as being able order via the DAS service.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['ting_das_types']['ting_das_data_well_types'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc($types),
    '#default_value' => _ting_das_get_default_well_types(),
  );

  $defaults = variable_get('ting_das_consent');
  $form['ting_das_consent'] = array(
    '#type' => 'fieldset',
    '#title' => t('Digital article server'),
    '#description' => t('Information to the user about the usage for the data sent and handled by the DAS service.'),
    '#tree' => TRUE,
  );

  $form['ting_das_consent']['prefix'] = array(
    '#type' => 'textarea',
    '#title' => t('Description of data usage'),
    '#rows' => 8,
    '#default_value' => isset($defaults['prefix']) ? $defaults['prefix'] : '',
  );

  $form['ting_das_consent']['label'] = array(
    '#type' => 'textarea',
    '#title' => t('Label text for the agree checkbox'),
    '#rows' => 4,
    '#default_value' => isset($defaults['label']) ? $defaults['label'] : t('I agree to the terms of usage'),
  );


  return system_settings_form($form);
}
