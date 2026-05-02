// Function : FUN_40162a80
// Address  : 0x40162a80
// Size     : 31 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_40162a80(undefined4 param_1,uint param_2)

{
  param_2 = param_2 & 0xff;
  if (1 >= param_2) {
    *(undefined4 *)(param_2 * 4 + _DAT_3ffc0034 + 0x3a8) = param_1;
  }
  memw();
  return 1 < param_2;
}

