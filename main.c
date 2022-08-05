#include <rcl/rcl.h>

int main(void){
	rcl_ret_t ret;

	rcl_context_t context = rcl_get_zero_initialized_context();

	rcl_init_options_t options = rcl_get_zero_initialized_init_options();
	ret = rcl_init_options_init(&options, rcutils_get_default_allocator());

	ret = rcl_init(0, NULL, &options, &context);
	ret = rcl_init_options_fini(&options);

	rcl_node_t node = rcl_get_zero_initialized_node();
	rcl_node_options_t node_ops = rcl_node_get_default_options();
	ret = rcl_node_init(&node, "node_name", "/node_ns", &context, &node_ops);

	printf("%s\n", rcl_node_get_name(&node));

	ret = rcl_node_fini(&node);
	return 0;
}
