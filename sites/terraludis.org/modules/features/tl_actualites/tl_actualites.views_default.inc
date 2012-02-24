<?php
/**
 * @file
 * tl_actualites.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tl_actualites_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'actualites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Actualités';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Toutes les Actualités';
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'group' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relation: Contenu : Auteur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relation: Abonnement OG : OG membership from Nœud */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = 0;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Contenu : Type d'Actualité */
  $handler->display->display_options['fields']['field_news_type']['id'] = 'field_news_type';
  $handler->display->display_options['fields']['field_news_type']['table'] = 'field_data_field_news_type';
  $handler->display->display_options['fields']['field_news_type']['field'] = 'field_news_type';
  $handler->display->display_options['fields']['field_news_type']['label'] = '';
  $handler->display->display_options['fields']['field_news_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_news_type']['field_api_classes'] = 0;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Champ: Contenu : Date de mise à jour */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Champ: Contenu : Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Champ: Contenu : Liens */
  $handler->display->display_options['fields']['field_news_links']['id'] = 'field_news_links';
  $handler->display->display_options['fields']['field_news_links']['table'] = 'field_data_field_news_links';
  $handler->display->display_options['fields']['field_news_links']['field'] = 'field_news_links';
  $handler->display->display_options['fields']['field_news_links']['label'] = '';
  $handler->display->display_options['fields']['field_news_links']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_links']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_links']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_news_links']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_links']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_links']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_links']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_links']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_news_links']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
  );
  $handler->display->display_options['fields']['field_news_links']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_news_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_news_links']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_news_links']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_news_links']['field_api_classes'] = 0;
  /* Champ: Contenu : Audience de groupes */
  $handler->display->display_options['fields']['group_audience']['id'] = 'group_audience';
  $handler->display->display_options['fields']['group_audience']['table'] = 'field_data_group_audience';
  $handler->display->display_options['fields']['group_audience']['field'] = 'group_audience';
  $handler->display->display_options['fields']['group_audience']['label'] = '';
  $handler->display->display_options['fields']['group_audience']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['external'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['group_audience']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['group_audience']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['group_audience']['alter']['html'] = 0;
  $handler->display->display_options['fields']['group_audience']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_audience']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['group_audience']['hide_empty'] = 0;
  $handler->display->display_options['fields']['group_audience']['empty_zero'] = 0;
  $handler->display->display_options['fields']['group_audience']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['group_audience']['click_sort_column'] = 'gid';
  $handler->display->display_options['fields']['group_audience']['type'] = 'tl_hacks_list_icons';
  $handler->display->display_options['fields']['group_audience']['group_rows'] = 1;
  $handler->display->display_options['fields']['group_audience']['delta_offset'] = '0';
  $handler->display->display_options['fields']['group_audience']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['group_audience']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['group_audience']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['group_audience']['field_api_classes'] = 0;
  /* Critère de tri: Contenu : Épinglé (en haut des listes) */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Critère de tri: Contenu : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'actualite' => 'actualite',
  );
  /* Critère de filtrage: Abonnement OG : Groupe OG gid */
  $handler->display->display_options['filters']['group']['id'] = 'group';
  $handler->display->display_options['filters']['group']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group']['field'] = 'group';
  $handler->display->display_options['filters']['group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['group']['expose']['operator_id'] = 'group_op';
  $handler->display->display_options['filters']['group']['expose']['label'] = 'Groupe OG gid';
  $handler->display->display_options['filters']['group']['expose']['operator'] = 'group_op';
  $handler->display->display_options['filters']['group']['expose']['identifier'] = 'group';
  $handler->display->display_options['filters']['group']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['group']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['group']['reduce_duplicates'] = 1;

  /* Display: Liste (Page) */
  $handler = $view->new_display('page', 'Liste (Page)', 'list');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Type d&#039;Actualité (field_news_type) */
  $handler->display->display_options['arguments']['field_news_type_value']['id'] = 'field_news_type_value';
  $handler->display->display_options['arguments']['field_news_type_value']['table'] = 'field_data_field_news_type';
  $handler->display->display_options['arguments']['field_news_type_value']['field'] = 'field_news_type_value';
  $handler->display->display_options['arguments']['field_news_type_value']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_news_type_value']['title'] = '%1';
  $handler->display->display_options['arguments']['field_news_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_news_type_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_news_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_news_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_news_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_news_type_value']['break_phrase'] = 0;
  $handler->display->display_options['path'] = 'actualites';

  /* Display: Accueil (Bloc) */
  $handler = $view->new_display('block', 'Accueil (Bloc)', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Dernières Actualités';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Contenu : Type d'Actualité */
  $handler->display->display_options['fields']['field_news_type']['id'] = 'field_news_type';
  $handler->display->display_options['fields']['field_news_type']['table'] = 'field_data_field_news_type';
  $handler->display->display_options['fields']['field_news_type']['field'] = 'field_news_type';
  $handler->display->display_options['fields']['field_news_type']['label'] = '';
  $handler->display->display_options['fields']['field_news_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_news_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_news_type']['field_api_classes'] = 0;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Champ: Contenu : Date de mise à jour */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'actualite' => 'actualite',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Critère de filtrage: Contenu : Promu en page d'accueil */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $translatables['actualites'] = array(
    t('Master'),
    t('Toutes les Actualités'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('auteur'),
    t('OG membership from node'),
    t('Groupe OG gid'),
    t('Liste (Page)'),
    t('Tous / Toutes'),
    t('%1'),
    t('Accueil (Bloc)'),
    t('Dernières Actualités'),
  );
  $export['actualites'] = $view;

  return $export;
}
