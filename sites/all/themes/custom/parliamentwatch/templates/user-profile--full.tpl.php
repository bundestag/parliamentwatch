<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['field_user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - $user_url: The URL to the detail page of the profile.
 *   - $display_name: The display name.
 *   - $field_user_picture: The profile picture.
 *   - $field_user_picture_copyright: The profile picture's copyright.
 *   - $field_user_constituency: The constituency.
 *   - $field_user_party: The party.
 *   - $questions: The number of questions the user has received.
 *   - $answers: The number of questions the user has answered.
 *   - $answer_ratio: The percentage of answered questions.
 *   - $questions_and_answers: The questions and answers section.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>



<article class="deputy detail"<?php print $attributes; ?>>
  <div class="container">

    <div class="deputy__intro">
      <div class="deputy__intro__sidebar">
        <header>
          <h1 class="deputy__title"><?php print render($user_profile['field_user_fname']); ?> <?php print render($user_profile['field_user_lname']); ?></h1>
          <div class="deputy__subtitle">
            <?php print render($user_profile['field_user_party']); ?> | Abgeordneter Bundestag
          </div>
        </header>
        <figure class="deputy__image">
          <?php print render($user_profile['field_user_picture']); ?>
          <a href="#" class="btn btn--block">Frage stellen</a>
          <figcaption>
            <?php print render($user_profile['field_user_picture_copyright']); ?>
          </figcaption>
        </figure>
      </div>
      <div class="deputy__intro__content">
        <div class="hstats">
          <div class="hstats__item hstats__item--donut-digit">
            <div class="hstats__item__display mh-item-nr" data-mh="hstats">
              <span class="d3 d3--gauge"
                    data-d3-gauge
                    data-percentage="<?php print $answer_ratio ?>"
                    data-track-width="10"
                    data-track-colour="ccc"
                    data-fill-colour="f46b3b"
                    data-text-colour="444"
                    data-stroke-colour="FFFFFF"
                    data-stroke-spacing="2">
                <span><?php print $answer_ratio; ?>%</span>
              </span>
            </div>
            <div class="hstats__item__label mh-item-nr" data-mh="hstats">
              <div class="hstats__item__label__value">
                <?php print $answers; ?>&thinsp;/&thinsp;<?php print $questions; ?>
              </div>
              <?php print format_plural($questions, t('Answered question'), t('Answered questions')) ?>
              <i class="icon icon-info" data-tooltip-content="<?php print t('tooltip-profil-answered-questions') ?>"></i>
            </div>
          </div>
          <div class="hstats__item hstats__item--donut-digit">
            <div class="hstats__item__display mh-item-nr" data-mh="hstats">
              <span class="d3 d3--gauge"
                    data-d3-gauge
                    data-percentage="68"
                    data-track-width="10"
                    data-track-colour="ccc"
                    data-fill-colour="f46b3b"
                    data-text-colour="444"
                    data-stroke-colour="FFFFFF"
                    data-stroke-spacing="2">
                <span><?php print $answer_ratio; ?>%</span>
              </span>
            </div>
            <div class="hstats__item__label mh-item-nr" data-mh="hstats">
              <div class="hstats__item__label__value">
                xx&thinsp;/&thinsp;XX
              </div>
              <?php print format_plural($user_profile['field_user_questions_get']['#items'][0]['value'], t('Vote by name'), t('Votes by name')) ?>
              <i class="icon icon-info" data-tooltip-content="<?php print t('tooltip-profil-votes-by-name') ?>"></i>
            </div>
          </div>

          <div class="hstats__item hstats__item--digit">
            <div class="hstats__item__label mh-item-nr" data-mh="hstats">
              <div class="hstats__item__label__value">
                <span class="hstats__item__label__value_min">160.000</span> € &ndash; <span class="hstats__item__label__value_max">220.000</span> €
              </div>
              <?php print t('Additional income min.') ?> <i class="icon icon-info" data-tooltip-content="<?php print t('tooltip-profil-additional-income') ?>"></i> <?php print t('Additional income max.') ?>
            </div>
          </div>

        </div>

        <dl class="dl">
          <?php if ($user_profile['field_user_birthday']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_birthday']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_birthday'][0]['#markup']; ?> (<?php print $user_profile['field_user_age'][0]['#markup']; ?> Jahre)</dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_childs']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_childs']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_childs'][0]['#markup']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_marriage_status']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_marriage_status']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_marriage_status'][0]['#markup']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_address']['#items'][0]['locality']): ?>
            <dt class="dl__dt"><?php print t('Wohnort') ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_address']['#items'][0]['locality']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_education']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_education']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_education'][0]['#markup']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_children']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_children']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_children'][0]['#markup']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_list']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_list']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_list'][0]['#markup']; ?><?php if ($user_profile['field_user_list_position']): ?>, Platz <?php print $user_profile['field_user_list_position'][0]['#markup']; ?><?php endif; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_parliament']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_parliament']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_parliament'][0]['#markup']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_election_result']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_election_result']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_election_result'][0]['#markup']; ?></dd>
          <?php endif; ?>
          <?php if ($user_profile['field_user_constituency']): ?>
            <dt class="dl__dt"><?php print $user_profile['field_user_constituency']['#title']; ?></dt>
            <dd class="dl__dd"><?php print $user_profile['field_user_constituency'][0]['#markup']; ?></dd>
          <?php endif; ?>

        </dl>
      </div>
    </div>
  </div>
  <div class="tabs">
    <div class="tabs__navigation">
      <div class="container">
        <ul class="nav nav--tab">
          <li class="nav__item nav__item--active"><a class="nav__item__link" href="#fragen-und-antworten" data-tab-content="fragen-und-antworten">Fragen & Antworten</a></li>
          <li class="nav__item"><a class="nav__item__link" href="#abstimmverhalten" data-tab-content="abstimmverhalten">Abstimmverhalten</a></li>
          <li class="nav__item"><a class="nav__item__link" href="#nebentaetigkeiten" data-tab-content="nebentaetigkeiten">Nebentätigkeiten</a></li>
          <li class="nav__item"><a class="nav__item__link" href="#ausschussmitgliedschaften" data-tab-content="ausschussmitgliedschaften">Ausschußmitgliedschaften</a></li>
        </ul>
      </div>
    </div>
    <section id="fragen-und-antworten" class="tabs__content tabs__content--active" data-tab-content="fragen-und-antworten">
      <div class="container">
        <div class="tabs__content__title option-title">
          <h2><a href="#" data-tab-content="fragen-und-antworten">Fragen & Antworten</a></h2>
        </div>
        <div class="tabs__content__content">
          <div class="swiper-container swiper-container--tile">
            <div class="swiper-wrapper">
              <?php print render($user_profile['dialogues']); ?>
            </div>
            <div class="swiper-button-prev"></div>
            <div class="swiper-button-next"></div>
          </div>
          <a href="#" class="btn btn--white btn--mobile-block">Alle Fragen in der Übersicht</a>
          <div class="tab-qa-stats">
            <div class="row">
              <div class="tab-qa-stats__col">
                <div class="hstats__item hstats__item--donut-digit">
                  <div class="hstats__item__display mh-item-nr" data-mh="qa_hstats">
                  <span class="d3 d3--gauge"
                        data-d3-gauge
                        data-percentage="30"
                        data-track-width="16"
                        data-track-colour="f6997a"
                        data-fill-colour="ffffff"
                        data-text-colour="ffffff"
                        data-stroke-colour="f68a66"
                        data-stroke-spacing="2">
                    <span>%</span>
                  </span>
                  </div>
                  <div class="hstats__item__label mh-item-nr" data-mh="qa_hstats">
                    84 <?php print t('of total') ?><br>89 <?php print t('questions answered') ?>
                  </div>
                </div>

                <div class="hstats__item hstats__item--donut-digit">
                  <div class="hstats__item__display mh-item-nr" data-mh="qa_hstats">
                  <span class="d3 d3--gauge"
                        data-d3-gauge
                        data-percentage="30"
                        data-track-width="16"
                        data-track-colour="f6997a"
                        data-fill-colour="ffffff"
                        data-text-colour="ffffff"
                        data-stroke-colour="f68a66"
                        data-stroke-spacing="2">
                    <span>%</span>
                  </span>
                  </div>
                  <div class="hstats__item__label mh-item-nr" data-mh="qa_hstats">
                    34 <?php print t('of total') ?><br>89 <?php print t('questions commented') ?>
                  </div>
                </div>
              </div>
              <div class="tab-qa-stats__col">
                <div class="hstats__item hstats__item--digit">
                  <span class="hstats__item__display mh-item-nr" data-mh="qa_hstats">16,5 h</span>
                  <span class="hstats__item__label mh-item-nr" data-mh="qa_hstats"><?php print t('average time to answer') ?></span>
                </div>
              </div>
              <div class="tab-qa-stats__col--large">
              <span class='d3 d3--bars-vertical'
                    data-d3-bars-vert
                    data-data='[{"name":"Katgeorie 1","url":"/location/bath","value":"18"},{"name":"Katgeorie 2","url":"/location/bath","value":"6"},{"name":"Katgeorie 3","url":"/location/bath","value":"12"},{"name":"Katgeorie 4","url":"/location/bath","value":"28"},{"name":"Katgeorie 5","url":"/location/bath","value":"18"},{"name":"Katgeorie 6","url":"/location/bath","value":"6"},{"name":"Katgeorie 7","url":"/location/bath","value":"12"},{"name":"Katgeorie 8","url":"/location/bath","value":"28"},{"name":"Katgeorie 9","url":"/location/bath","value":"18"},{"name":"Katgeorie 10","url":"/location/bath","value":"6"},{"name":"Katgeorie 11","url":"/location/bath","value":"12"},{"name":"Katgeorie 12","url":"/location/bath","value":"28"},{"name":"Katgeorie 13","url":"/location/bath","value":"18"},{"name":"Katgeorie 14","url":"/location/bath","value":"6"},{"name":"Katgeorie 15","url":"/location/bath","value":"12"},{"name":"Katgeorie 16","url":"/location/bath","value":"28"}]'
                    data-height='100'
                    data-fill-colour='ffffff'
                    data-stroke-colour='f68a66'>
                <span class="tooltip d3__tooltip"></span>
              </span>
              </div>
            </div>
          </div>
        </div>
      </div>
    </section>
    <section id="abstimmverhalten" class="tabs__content" data-tab-content="abstimmverhalten">
      <div class="container">
        <div class="tabs__content__title">
          <h2><a href="#" data-tab-content="abstimmverhalten">Abstimmverhalten</a></h2>
        </div>
        <div class="tabs__content__content">
          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. A ad atque ducimus error esse exercitationem fuga
            incidunt laudantium magni nemo, nobis nostrum omnis quae quaerat quia quo repellendus velit voluptatem.</p>
          <p>Amet natus, veritatis. Adipisci aperiam distinctio dolorum ea ex harum hic id incidunt inventore ipsa iusto,
            nesciunt obcaecati odit, officiis, praesentium provident quaerat saepe tempora vel velit. Deleniti
            dignissimos, sit?</p>
        </div>
      </div>
    </section>
    <section id="nebentaetigkeiten" class="tabs__content" data-tab-content="nebentaetigkeiten">
      <div class="container">
        <div class="tabs__content__title">
          <h2><a href="#" data-tab-content="nebentaetigkeiten">Nebentätigkeiten</a></h2>
        </div>
        <div class="tabs__content__content">
          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. A ad atque ducimus error esse exercitationem fuga
            incidunt laudantium magni nemo, nobis nostrum omnis quae quaerat quia quo repellendus velit voluptatem.</p>
          <p>Amet natus, veritatis. Adipisci aperiam distinctio dolorum ea ex harum hic id incidunt inventore ipsa iusto,
            nesciunt obcaecati odit, officiis, praesentium provident quaerat saepe tempora vel velit. Deleniti
            dignissimos, sit?</p>
        </div>
      </div>
    </section>
    <section id="ausschussmitgliedschaften" class="tabs__content" data-tab-content=ausschussmitgliedschaften">
      <div class="container">
        <div class="tabs__content__title">
          <h2><a href="#" data-tab-content="ausschussmitgliedschaften">Ausschußmitgliedschaften</a></h2>
        </div>
        <div class="tabs__content__content">
          <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. A ad atque ducimus error esse exercitationem fuga
            incidunt laudantium magni nemo, nobis nostrum omnis quae quaerat quia quo repellendus velit voluptatem.</p>
          <p>Amet natus, veritatis. Adipisci aperiam distinctio dolorum ea ex harum hic id incidunt inventore ipsa iusto,
            nesciunt obcaecati odit, officiis, praesentium provident quaerat saepe tempora vel velit. Deleniti
            dignissimos, sit?</p>
        </div>
      </div>
    </section>
  </div>
</article>


<br><br><br><br><br><br><br><br><br><br><br><br><br>
<pre>
  <?php //print_r($user_profile); ?>
</pre>