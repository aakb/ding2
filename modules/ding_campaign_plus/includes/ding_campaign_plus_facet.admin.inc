<?php
/**
 * @file
 * Contains the form functions used to build the "Facet triggers" tabs.
 */

/**
 * Builds the from rule selection elements.
 *
 * This are the rules known from the ding campaign module.
 */
function _ding_campaign_plus_facet_triggers_form($form, &$form_state) {
  $values = isset($form_state['values']['tabs']['facet']['rules']) ? $form_state['values']['tabs']['facet']['rules'] : array();

  // Get campaign rule from node.
  if (empty($values) && isset($form_state['node']->ding_campaign_plus)) {
    $values = _ding_campaign_plus_filter_rules($form_state['node']->nid, 'facet', $form_state['node']->ding_campaign_plus);
    $values['count'] = count($values);
  }
  $count = !empty($values['count']) ? $values['count'] : 0;

  // Check if remove button has been pressed. If so remove element from
  // form_state values.
  if (isset($form_state['triggering_element'])) {
    if ($form_state['triggering_element']['#op'] === 'remove' && substr($form_state['triggering_element']['#name'], 0, 18) === 'remove_facet_rule_') {
      $rule = 'rule_' . $form_state['triggering_element']['#rule'];
      unset($values[$rule]);
      unset($form_state['values']['tabs']['facet']['rules'][$rule]);
    }
  }

  $triggers = array(
    '#prefix' => '<div id="ding-campaign-facet-triggers">',
    '#suffix' => '</div>',
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'ding_campaign_plus') . '/js/ding_campaign_plus.admin.js',
      )
    ),
  );

  // If this form is "add another" or "remove" build rules already form_state
  // values.
  foreach ($values as $key => $value) {
    if (substr($key, 0, 4) === "rule") {
      $triggers[$key] = _ding_campaign_plus_facet_rule_form(substr($key, 5), $value);
    }
  }

  // If not a remove operation add one more element.
  if (!isset($form_state['triggering_element'])) {
    $triggers['rule_' . $count] = _ding_campaign_plus_facet_rule_form($count);
  }
  else if ($form_state['triggering_element']['#name'] === 'add_another_facet') {
    // Check if it was this sub-form that need another element added if not
    // exit to prevent extra elements being generated.
    $count++;
    $triggers['rule_' . $count] = _ding_campaign_plus_facet_rule_form($count);
  }

  $triggers['count'] = array(
    '#type' => 'hidden',
    '#value' => $count,
  );

  $triggers['add_rule'] = array(
    '#type' => 'button',
    '#name' => 'add_another_facet',
    '#value' => t('Add another'),
    '#ajax' => array(
      'callback' => '_ding_campaign_plus_facet_rule_ajax_callback',
      'wrapper' => 'ding-campaign-facet-triggers',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $triggers;
}

/**
 * Return the facet rules part of the form.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   Form state array.
 *
 * @return array
 *   Form element - rule fields.
 */
function _ding_campaign_plus_facet_rule_ajax_callback(array $form, array $form_state) {
  return $form['triggers']['tabs']['facet']['rules'];
}

/**
 * Rule form fields chunk.
 *
 * @param int $number
 *   The rule number (used for UI numbering).
 * @param array $default_values
 *   The default values for the fields.
 *
 * @return array
 *   Rule fields structure.
 */
function _ding_campaign_plus_facet_rule_form($number = 0, $default_values = array()) {
  $form = array(
    '#type' => 'fieldset',
    '#title' => t('Rule %num',array('%num' => $number)),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $options = array();
  $facets = variable_get('ding_facetbrowser_facets', array());
  foreach ($facets as $facet) {
    $options[$facet['name']] = $facet['title'];
  }

  $form['facet_type'] = array(
    '#type' => 'select',
    '#title' => t('Facet Type'),
    '#default_value' => isset($default_values['type']) ? $default_values['type'] : 'facet.type',
    '#options' => $options,
    '#attributes' => array(
      'class' => array('js-fact-type'),
    )
  );

  $options = _ting_fetch_well_types();
  $options = array_keys($options);
  $options = array_combine($options, $options);
  $form['facet_value_select_type'] = array(
    '#type' => 'select',
    '#title' => t('Facet'),
    '#default_value' => isset($default_values['facet_value_select_type']) ? $default_values['facet_value_select_type'] : array(),
    '#options' => $options,
    '#multiple' => TRUE,
    '#size' => min(8, count($options)),
  );

  $options = _ting_fetch_well_sources();
  $options = array_keys($options);
  $options = array_combine($options, $options);
  $form['facet_value_select_source'] = array(
    '#type' => 'select',
    '#title' => t('Facet'),
    '#default_value' => isset($default_values['facet_value_select_source']) ? $default_values['facet_value_select_source'] : array(),
    '#options' => $options,
    '#multiple' => TRUE,
    '#size' => min(8, count($options)),
  );

  $form['facet_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Facet value'),
    '#default_value' => isset($default_values['facet_value']) ? $default_values['facet_value'] : '',
    '#size' => 64,
    '#maxlength' => 255,
  );

  $form['remove_rule_' . $number] = array(
    '#type' => 'button',
    '#value' => t('Remove'),
    '#name' => 'remove_facet_rule_' . $number,
    '#op' => 'remove',
    '#rule' => $number,
    '#ajax' => array(
      'callback' => '_ding_campaign_plus_facet_rule_ajax_callback',
      'wrapper' => 'ding-campaign-facet-triggers',
      'method' => 'replace',
      'effect' => 'fade'
    ),
  );

  return $form;
}

/**
 * Auto complete handler for rules.
 *
 * @param string $type
 *   Type.
 * @param string $input
 *   Input.
 */
function _ding_campaign_plus_facet_admin_autocomplete($type, $input) {
  $matches = array();

  drupal_json_output($matches);
}

/**
 * @TODO: Documentation
 */
function _ding_campaign_plus_facet_triggers_form_submit($form, &$form_state) {
  /**
   * TODO: Save data ?
   */
}