// Function : FUN_400ec888
// Address  : 0x400ec888
// Size     : 23 bytes


void FUN_400ec888(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_400f9a40(*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}

