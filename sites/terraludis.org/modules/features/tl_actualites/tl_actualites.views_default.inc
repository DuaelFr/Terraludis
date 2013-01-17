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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'Toutes les actualités';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'news-type-[field_news_type]';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Vide';
  $handler->display->display_options['empty']['area']['content'] = 'Aucune actualité n\'a été publiée dans cet Univers.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relation: Contenu : Auteur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relation: Abonnement OG : OG membership from Nœud */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Champ: Contenu : Type d'Actualité */
  $handler->display->display_options['fields']['field_news_type']['id'] = 'field_news_type';
  $handler->display->display_options['fields']['field_news_type']['table'] = 'field_data_field_news_type';
  $handler->display->display_options['fields']['field_news_type']['field'] = 'field_news_type';
  $handler->display->display_options['fields']['field_news_type']['label'] = '';
  $handler->display->display_options['fields']['field_news_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_type']['type'] = 'tl_hacks_list_translitered';
  /* Champ: Contenu : Audience de groupes */
  $handler->display->display_options['fields']['group_audience']['id'] = 'group_audience';
  $handler->display->display_options['fields']['group_audience']['table'] = 'field_data_group_audience';
  $handler->display->display_options['fields']['group_audience']['field'] = 'group_audience';
  $handler->display->display_options['fields']['group_audience']['label'] = '';
  $handler->display->display_options['fields']['group_audience']['exclude'] = TRUE;
  $handler->display->display_options['fields']['group_audience']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_audience']['click_sort_column'] = 'gid';
  $handler->display->display_options['fields']['group_audience']['type'] = 'tl_hacks_list_icons';
  $handler->display->display_options['fields']['group_audience']['delta_offset'] = '0';
  $handler->display->display_options['fields']['group_audience']['multi_type'] = 'ul';
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Nombre de commentaires */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  $handler->display->display_options['fields']['comment_count']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['format_plural_singular'] = '1 commentaire';
  $handler->display->display_options['fields']['comment_count']['format_plural_plural'] = '@count commentaires';
  /* Champ: Contenu : Date de mise à jour */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '- ';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'par ';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Champ: DIV Title */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'DIV Title';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="news-title">
  <div class="univers">[group_audience]</div>
  <h2>[title]</h2>
  <div class="comment-count">[comment_count]</div>
  <div class="metadata">- [changed] par [name]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Champ: Contenu : Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Champ: Contenu : Vignette */
  $handler->display->display_options['fields']['field_picture']['id'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['table'] = 'field_data_field_picture';
  $handler->display->display_options['fields']['field_picture']['field'] = 'field_picture';
  $handler->display->display_options['fields']['field_picture']['label'] = '';
  $handler->display->display_options['fields']['field_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_picture']['settings'] = array(
    'image_style' => 'news_list',
    'image_link' => 'content',
  );
  /* Champ: DIV Content */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'DIV Content';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="news-content">
  <div class="picture">[field_picture]</div>
  <div class="teaser">[body]</div>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['filters']['group']['value'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
  );
  $handler->display->display_options['filters']['group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['group']['expose']['operator_id'] = 'group_op';
  $handler->display->display_options['filters']['group']['expose']['label'] = 'Afficher les Univers : ';
  $handler->display->display_options['filters']['group']['expose']['operator'] = 'group_op';
  $handler->display->display_options['filters']['group']['expose']['identifier'] = 'group';
  $handler->display->display_options['filters']['group']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['group']['expose']['reduce'] = TRUE;

  /* Display: Liste (Page) */
  $handler = $view->new_display('page', 'Liste (Page)', 'list');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Type d&#039;Actualité (field_news_type) */
  $handler->display->display_options['arguments']['field_news_type_value']['id'] = 'field_news_type_value';
  $handler->display->display_options['arguments']['field_news_type_value']['table'] = 'field_data_field_news_type';
  $handler->display->display_options['arguments']['field_news_type_value']['field'] = 'field_news_type_value';
  $handler->display->display_options['arguments']['field_news_type_value']['exception']['title'] = 'Tous / Toutes';
  $handler->display->display_options['arguments']['field_news_type_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_news_type_value']['title'] = '%1';
  $handler->display->display_options['arguments']['field_news_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_news_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_news_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_news_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_news_type_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_news_type_value']['case'] = 'ucfirst';
  $handler->display->display_options['arguments']['field_news_type_value']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['field_news_type_value']['transform_dash'] = TRUE;
  $handler->display->display_options['path'] = 'actualites';

  /* Display: Accueil (Bloc) */
  $handler = $view->new_display('block', 'Accueil (Bloc)', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Dernières Actualités';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'news-type-[field_news_type]';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'created' => 'created',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    t('Toutes les actualités'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('Vide'),
    t('Aucune actualité n\'a été publiée dans cet Univers.'),
    t('auteur'),
    t('OG membership from node'),
    t('.'),
    t('- '),
    t('par '),
    t('<div class="news-title">
  <div class="univers">[group_audience]</div>
  <h2>[title]</h2>
  <div class="comment-count">[comment_count]</div>
  <div class="metadata">- [changed] par [name]</div>
</div>'),
    t('<div class="news-content">
  <div class="picture">[field_picture]</div>
  <div class="teaser">[body]</div>
</div>'),
    t('Afficher les Univers : '),
    t('Liste (Page)'),
    t('plus'),
    t('Tous / Toutes'),
    t('%1'),
    t('Accueil (Bloc)'),
    t('Dernières Actualités'),
  );
  $export['actualites'] = $view;

  return $export;
}
