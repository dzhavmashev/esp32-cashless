// Function : FUN_400f13c0
// Address  : 0x400f13c0
// Size     : 45 bytes


int FUN_400f13c0(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_40184778(param_1);
  iVar3 = -1;
  if (param_3 < uVar1) {
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      param_1 = (undefined4 *)*param_1;
    }
    iVar2 = func_0x4008bdd4((int)param_1 + param_3,param_2);
    iVar3 = -1;
    if (iVar2 != 0) {
      iVar3 = iVar2 - (int)param_1;
    }
  }
  return iVar3;
}

