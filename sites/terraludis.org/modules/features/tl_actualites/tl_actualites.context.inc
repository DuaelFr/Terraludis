<?php
/**
 * @file
 * tl_actualites.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tl_actualites_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'actualites';
  $context->description = 'Type de contenu actualités';
  $context->tag = 'Content types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'actualite' => 'actualite',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'actualites',
    'menu' => 'actualites',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content types');
  t('Type de contenu actualités');
  $export['actualites'] = $context;

  return $export;
}
