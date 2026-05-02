// Function : FUN_40183f40
// Address  : 0x40183f40
// Size     : 33 bytes


void FUN_40183f40(undefined1 param_1,undefined1 *param_2)

{
  if (param_2 != (undefined1 *)0x0) {
    param_2[8] = param_2[8] & 0x80 | 6;
    *param_2 = param_1;
  }
  return;
}

