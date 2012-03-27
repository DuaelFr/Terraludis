<?php
/**
 * @file
 * tl_context_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tl_context_global_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Page d\'accueil';
  $context->tag = 'Contextes globaux';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-actualites-block' => array(
          'module' => 'views',
          'delta' => 'actualites-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-evenements-block_1' => array(
          'module' => 'views',
          'delta' => 'evenements-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contextes globaux');
  t('Page d\'accueil');
  $export['front'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = 'Contexte global du site';
  $context->tag = 'Contextes globaux';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nice_menus-1' => array(
          'module' => 'nice_menus',
          'delta' => 1,
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-groupes-block_universe' => array(
          'module' => 'views',
          'delta' => 'groupes-block_universe',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'user-online' => array(
          'module' => 'user',
          'delta' => 'online',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'shoutbox-shoutbox' => array(
          'module' => 'shoutbox',
          'delta' => 'shoutbox',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'header',
          'weight' => '-10',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'header',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header2',
          'weight' => '-10',
        ),
        'menu-menu-menu-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-menu-footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contexte global du site');
  t('Contextes globaux');
  $export['global'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'no-front';
  $context->description = 'Tout sauf l\'accueil';
  $context->tag = 'Contextes globaux';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contextes globaux');
  t('Tout sauf l\'accueil');
  $export['no-front'] = $context;

  return $export;
}
