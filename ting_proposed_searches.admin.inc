<?php

/**
 * @file
 * Admin settings for search suggestions.
 */

/**
 * Suggestion form settings.
 */
function ting_proposed_searches_admin() {
  $default_settings = ting_proposed_searches_settings();

  $form['ting_proposed_searches_webservice'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings', array(), array('context' => 'ting_proposed_searches')),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
  );

  $form['ting_proposed_searches_webservice']['ting_proposed_searches_rest_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Suggestions REST Service URL'),
    '#size' => 73,
    '#description' => t('URL to Autocomplete webservice. F.ex.: http://opensuggestion.addi.dk/b3.0_2.0/rest', array(), array('context' => 'ting_proposed_searches')),
    '#default_value' => variable_get('ting_proposed_searches_rest_url', NULL),
    '#required' => TRUE,
  );

  $form['ting_proposed_searches_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Suggestion settings', array(), array('context' => 'ting_proposed_searches')),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['ting_proposed_searches_settings']['index'] = array(
    '#type' => 'textfield',
    '#title' => t('Match index', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 25,
    '#default_value' => $default_settings['index'],
    '#required' => TRUE,
  );

  $form['ting_proposed_searches_settings']['facetIndex'] = array(
    '#type' => 'textfield',
    '#title' => t('Facet Index', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 25,
    '#default_value' => $default_settings['facetIndex'],
    '#required' => TRUE,
  );

  $form['ting_proposed_searches_settings']['filterQuery'] = array(
    '#type' => 'textfield',
    '#title' => t('Filter Query', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 25,
    '#default_value' => $default_settings['filterQuery'],
  );

  $form['ting_proposed_searches_settings']['agency'] = array(
    '#type' => 'textfield',
    '#title' => t('Agency', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 26,
    '#default_value' => $default_settings['agency'],
  );

  $form['ting_proposed_searches_settings']['profile'] = array(
    '#type' => 'textfield',
    '#title' => t('Profile', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 26,
    '#default_value' => $default_settings['profile'],
  );

  $form['ting_proposed_searches_settings']['maxSuggestions'] = array(
    '#type' => 'textfield',
    '#title' => t('Max suggestions', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 26,
    '#default_value' => $default_settings['maxSuggestions'],
  );

  $form['ting_proposed_searches_settings']['maxTime'] = array(
    '#type' => 'textfield',
    '#title' => t('Max request time', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 26,
    '#default_value' => $default_settings['maxTime'],
  );

  $form['ting_proposed_searches_settings']['highlight'] = array(
    '#type' => 'checkbox',
    '#title' => t('Highlight', array(), array('context' => 'ting_proposed_searches')),
    '#description' => t('If checked, search prefix will be enclosed in highlight prefix and suffix', array(), array('context' => 'ting_proposed_searches')),
    '#default_value' => $default_settings['highlight'],
    '#return_value' => 'true',
  );

  $form['ting_proposed_searches_settings']['highlight.pre'] = array(
    '#type' => 'textfield',
    '#title' => t('Highlight prefix', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 26,
    '#default_value' => $default_settings['highlight.pre'],
  );

  $form['ting_proposed_searches_settings']['highlight.post'] = array(
    '#type' => 'textfield',
    '#title' => t('Highlight suffix', array(), array('context' => 'ting_proposed_searches')),
    '#size' => 26,
    '#default_value' => $default_settings['highlight.post'],
  );

  $form['ting_proposed_searches_help'] = array(
    '#type' => 'fieldset',
    '#title' => t('Suggestions help', array(), array('context' => 'ting_proposed_searches')),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['ting_proposed_searches_help']['description'] = array(
    '#theme' => 'table',
    '#rows' => array(
      array(t('Match index:', array(), array('context' => 'ting_proposed_searches')),
        t('The index to find word matches in.<br/>
               If a term index, single terms are returned, while phrase indexes return entire phrases. Only entries in the specified index that begin with the specified query string are returned. For term indexes the query string can only contain one term<br/>
               F.ex.: scanterm.mainTitle + query: "kan" will match "<b>Kan</b>dis", or scanphrase.mainTitle + query: "kan" will match "<b>Kan</b>sas city"', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Facet index:', array(), array('context' => 'ting_proposed_searches')),
        t('The index to get suggestions from.<br/>
               This variant looks in the specified index for entries that contain the words from specified query string and then counts results in groups based on the specified facet index. This will also provide suggestions for phrases that contain the words from the query string.<br/>
               Care should be taken in selecting a suitable pair of indexes. The facet index should be an index generated from the same data as the match index. The match index should be a term index and the facet index should be a phrase index<br/>
               F.ex.: scanphrase.mainTitle (combined with match index: scanterm.mainTitle) + query: "kan" will match "From Impressionism to <b>Kan</b>dinsky"', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Query filter:', array(), array('context' => 'ting_proposed_searches')),
        t('A query that may be used to filter the area you want to get suggestions from. F.ex.: term.workType=literature', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Agency:', array(), array('context' => 'ting_proposed_searches')),
        t('Only get suggestions from data accessible to the specified library ID. F.ex.: 715100', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Profile:', array(), array('context' => 'ting_proposed_searches')),
        t('Only get suggestions from data accessible to the specified search profile, as defined in the VIP database.', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Max suggestions:', array(), array('context' => 'ting_proposed_searches')),
        t('Maximum suggestions to return. Default 10', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Max request time:', array(), array('context' => 'ting_proposed_searches')),
        t('Maximum request time in milliseconds. Default 2000', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Highlight:', array(), array('context' => 'ting_proposed_searches')),
        t('Add prefix and suffix around strings that match the query.', array(), array('context' => 'ting_proposed_searches'))),
      array(t('Highlight prefix & suffix:', array(), array('context' => 'ting_proposed_searches')),
        t('Defaults to &lt;em&gt; & &lt;/em&gt;.', array(), array('context' => 'ting_proposed_searches'))),
    ),
    '#attributes' => array('class' => array('table-class')),
    '#empty' => t('Your table is empty'),
  );

  return system_settings_form($form);
}

/**
 * Validation handler for ting_proposed_searches_admin.
 */
function ting_proposed_searches_admin_validate($form, &$form_state) {
  $form_state['values']['ting_proposed_searches_rest_url'] = trim($form_state['values']['ting_proposed_searches_rest_url']);
}
