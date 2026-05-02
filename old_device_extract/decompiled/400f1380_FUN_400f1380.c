// Function : FUN_400f1380
// Address  : 0x400f1380
// Size     : 42 bytes


undefined1 FUN_400f1380(int *param_1,uint param_2)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar1 = FUN_40184778(param_1);
  uVar2 = 0;
  if ((param_2 < uVar1) &&
     (((*(byte *)((int)param_1 + 0xf) & 0x80) != 0 ||
      (param_1 = (int *)*param_1, param_1 != (int *)0x0)))) {
    uVar2 = *(undefined1 *)((int)param_1 + param_2);
  }
  return uVar2;
}

