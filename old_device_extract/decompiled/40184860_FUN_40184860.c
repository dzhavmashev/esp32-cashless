// Function : FUN_40184860
// Address  : 0x40184860
// Size     : 5 bytes


void FUN_40184860(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  while( true ) {
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
    if (param_2 <= param_1) break;
    uVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = uVar1;
  }
  return;
}

