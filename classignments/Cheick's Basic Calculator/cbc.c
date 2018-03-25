/**
* cbc.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* The entry point of Cheick's Basic Calculator; a basic calculator with a GUI. It performs additions, subtraction, 
* multiplication, and division on integers and floating-point numbers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

/* Macros declarations. */
#define MAX_RESULT_DIGITS 32

/* Types declarations. */

// A structure containing the list of all widgets who will be used directly within the code.
typedef struct
{
    GtkWidget *display_entry;
    GtkWidget *op_entry;
    
} WidgetsList;

// An enumeration of the operators.
typedef enum 
{
    None,
    Plus, 
    Minus, 
    Times, 
    Over
} ArithmeticOperator;

// A type representing an expression, such as 1 + 2 = 3.
typedef struct
{
    float A;
    float B;
    float R;
    gboolean hasA;
    gboolean hasB;
    gboolean hasO;
    gboolean hasR;
    ArithmeticOperator O;
} Expression;

// A type to represent the different actions performed. Digit means a digit button clicked, etc.
typedef enum
{
    Digit = 1,
    Operation,
    Equals
} ActionType;

/* Variables declarations. */

// Variable containing all widgets.
WidgetsList *widgets;
// Variable containong the expression being computed.
Expression current_expression;

/* Functions definitions. */

const gchar *get_op_entry_text(void)
{
    return gtk_entry_get_text(GTK_ENTRY(widgets->op_entry));
}

void set_op_entry_text(const gchar *value)
{
    // Appends new text to old one.
    GString *current_content = g_string_new(get_op_entry_text());
    GString *new_content = g_string_append(current_content, value);

    gtk_entry_set_text(GTK_ENTRY(widgets->op_entry), new_content -> str);
}

void set_display_entry_text(const gchar *value)
{
    // Appends new text to old one.
    GString *current_content = g_string_new(gtk_entry_get_text(GTK_ENTRY(widgets->display_entry)));
    GString *new_content = g_string_append(current_content, " ");
    new_content = g_string_append(new_content, value);    

    gtk_entry_set_text(GTK_ENTRY(widgets->display_entry), new_content -> str);
}

// Sets value of one operand at a time.
gboolean set_current_expression_operand(float value)
{
    // Checks expression variables flags before setting value.
    if (!current_expression.hasA)
    {
        current_expression.A = value;
        current_expression.hasA = TRUE;
        return TRUE;
    }
    else if (!current_expression.hasB)
    {
        current_expression.B = value;
        current_expression.hasB = TRUE;
        return TRUE;
    }
    else
        return FALSE;
}

gboolean set_current_expression_operator(ArithmeticOperator operator)
{
    if (!current_expression.hasO)
    {
        current_expression.O = operator;
        current_expression.hasO = TRUE;
        return TRUE;
    }
    else
        return FALSE;
}

void perform_operation(void)
{
    current_expression.hasR = TRUE;
    switch (current_expression.O)
    {
        case Plus:
            current_expression.R = current_expression.A + current_expression.B;
            break;
        case Minus:
            current_expression.R = current_expression.A - current_expression.B;
            break;
        case Times:
            current_expression.R = current_expression.A * current_expression.B;
            break;
        case Over:
            current_expression.R = current_expression.A / current_expression.B;
            break;
        default:
            current_expression.hasR = FALSE;
            break;
    }
}

/* Event handlers. */

// Closes the main_appwindow.
void destroy_main_appwindow(void)
{
    gtk_main_quit();
}

void clicked_clear_button(void)
{
    gtk_entry_set_text(GTK_ENTRY(widgets->op_entry), "");
}

// Initializes the interface and the current expression.
void clicked_reset_button(void)
{
    gtk_entry_set_text(GTK_ENTRY(widgets->display_entry), "");
    current_expression.hasA = FALSE;
    current_expression.hasB = FALSE;
    current_expression.hasO = FALSE;
    current_expression.hasR = FALSE;
    clicked_clear_button();
}

void clicked_digit_button(GtkButton *button)
{
    // Gets digit's value from label appends it to the op_entry widget.
    set_op_entry_text(gtk_button_get_label(button));
}

void clicked_plus_button(void)
{
    if (!current_expression.hasA)
    {
        const gchar *button_value = get_op_entry_text();
        set_current_expression_operand(strtof(button_value, NULL));
        set_display_entry_text(button_value);
        set_current_expression_operator(Plus);
        set_display_entry_text("+");
        clicked_clear_button();
    }
}

void clicked_minus_button(void)
{
    if (!current_expression.hasA)
    {
        const gchar *button_value = get_op_entry_text();
        set_current_expression_operand(strtof(button_value, NULL));
        set_display_entry_text(button_value);
        set_current_expression_operator(Minus);
        set_display_entry_text("-");
        clicked_clear_button();
    }
}

void clicked_times_button(void)
{
    if (!current_expression.hasA)
    {
        const gchar *button_value = get_op_entry_text();
        set_current_expression_operand(strtof(button_value, NULL));
        set_display_entry_text(button_value);
        set_current_expression_operator(Times);
        set_display_entry_text("x");
        clicked_clear_button();
    }
}

void clicked_over_button(void)
{
    if (!current_expression.hasA)
    {
        const gchar *button_value = get_op_entry_text();
        set_current_expression_operand(strtof(button_value, NULL));
        set_display_entry_text(button_value);
        set_current_expression_operator(Over);
        set_display_entry_text("/");
        clicked_clear_button();
    }
}

void clicked_equals_button(void)
{
    if (!current_expression.hasR)
    {
        const gchar *button_value = get_op_entry_text();
        set_current_expression_operand(strtof(button_value, NULL));
        set_display_entry_text(button_value);
        perform_operation();
        set_display_entry_text("=");
        gchar *result = g_new(char, MAX_RESULT_DIGITS);
        snprintf(result, MAX_RESULT_DIGITS, "%f", current_expression.R);
        set_display_entry_text(result);
        clicked_clear_button();
    }
}

int main(int argc, char *argv[])
{
    // Builds the interface from an XML UI.
    GtkBuilder *builder;
    GtkWidget *main_appwindow;
    // Allocates memory to pointers in the WidgetsList struct.
    widgets = g_slice_new(WidgetsList);

    // Initializes everything needed to operate the toolkit and parses some standard commandline options.
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "cbc-ui.glade", NULL);

    // Loads UI widgets from XML file.
    main_appwindow = GTK_WIDGET(gtk_builder_get_object(builder, "main_appwindow"));
    widgets->display_entry  = GTK_WIDGET(gtk_builder_get_object(builder, "display_entry"));
    widgets->op_entry  = GTK_WIDGET(gtk_builder_get_object(builder, "op_entry"));  
    
    // Binds UI widgets with their event handlers.
    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    clicked_reset_button();

    gtk_widget_show(main_appwindow);
    gtk_main();

    return 0;
}