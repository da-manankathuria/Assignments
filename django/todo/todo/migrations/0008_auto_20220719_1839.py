# Generated by Django 3.2.14 on 2022-07-19 13:09

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('todo', '0007_alltodos_author'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='alltodos',
            name='author',
        ),
        migrations.AlterField(
            model_name='alltodos',
            name='id',
            field=models.AutoField(primary_key=True, serialize=False),
        ),
    ]
