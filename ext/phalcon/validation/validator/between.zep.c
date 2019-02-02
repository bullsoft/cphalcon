
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\Between
 *
 * Validates that a value is between an inclusive range of two values.
 * For a value x, the test is passed if minimum<=x<=maximum.
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Between;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "price",
 *     new Between(
 *         [
 *             "minimum" => 0,
 *             "maximum" => 100,
 *             "message" => "The price must be between 0 and 100",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "price",
 *         "amount",
 *     ],
 *     new Between(
 *         [
 *             "minimum" => [
 *                 "price"  => 0,
 *                 "amount" => 0,
 *             ],
 *             "maximum" => [
 *                 "price"  => 100,
 *                 "amount" => 50,
 *             ],
 *             "message" => [
 *                 "price"  => "The price must be between 0 and 100",
 *                 "amount" => "The amount must be between 0 and 50",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Between) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Between, phalcon, validation_validator_between, phalcon_validation_validator_ce, phalcon_validation_validator_between_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Between, validate) {

	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, minimum, maximum, message, label, replacePairs, code, _0, _1$$3, _2$$4, _4$$5, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&minimum);
	ZVAL_UNDEF(&maximum);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "minimum");
	ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "maximum");
	ZEPHIR_CALL_METHOD(&maximum, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&minimum) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &minimum, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/between.zep", 79 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&minimum, &_1$$3);
	}
	if (Z_TYPE_P(&maximum) == IS_ARRAY) {
		zephir_array_fetch(&_2$$4, &maximum, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/between.zep", 83 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&maximum, &_2$$4);
	}
	_3 = ZEPHIR_LT(&value, &minimum);
	if (!(_3)) {
		_3 = ZEPHIR_GT(&value, &maximum);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "Between");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 3, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_5$$5, "strtr", NULL, 50, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "Between");
		ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 299, &_5$$5, field, &_6$$5, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_4$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

