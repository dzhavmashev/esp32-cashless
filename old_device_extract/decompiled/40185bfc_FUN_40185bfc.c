// Function : FUN_40185bfc
// Address  : 0x40185bfc
// Size     : 36 bytes


undefined4 FUN_40185bfc(int *param_1,int param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffff94;
  if (0 < *param_1 - param_2) {
    puVar1 = (undefined1 *)(*param_1 + -1);
    *param_1 = (int)puVar1;
    uVar2 = 1;
    *puVar1 = param_3;
    memw();
  }
  memw();
  return uVar2;
}

