// Function : FUN_400f1354
// Address  : 0x400f1354
// Size     : 40 bytes


undefined1 * FUN_400f1354(int *param_1,uint param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_40184778(param_1);
  if ((param_2 < uVar1) &&
     (((*(byte *)((int)param_1 + 0xf) & 0x80) != 0 ||
      (param_1 = (int *)*param_1, param_1 != (int *)0x0)))) {
    puVar2 = (undefined1 *)((int)param_1 + param_2);
  }
  else {
    puVar2 = &DAT_3ffc54f4;
    DAT_3ffc54f4 = 0;
  }
  return puVar2;
}

