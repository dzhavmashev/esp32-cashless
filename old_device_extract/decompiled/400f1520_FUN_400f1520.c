// Function : FUN_400f1520
// Address  : 0x400f1520
// Size     : 55 bytes


void FUN_400f1520(undefined4 param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_3;
  if (param_4 < param_3) {
    uVar2 = param_4;
    param_4 = param_3;
  }
  FUN_400f0be8(param_1,&DAT_3f42161d);
  uVar1 = FUN_40184778(param_2);
  if (uVar2 < uVar1) {
    if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
      param_2 = (undefined4 *)*param_2;
    }
    FUN_400f0bb0(param_1,(int)param_2 + uVar2,
                 ((uVar1 < param_4) * uVar1 + (uVar1 >= param_4) * param_4) - uVar2);
  }
  return;
}

