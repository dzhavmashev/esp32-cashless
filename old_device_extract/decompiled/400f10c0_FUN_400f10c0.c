// Function : FUN_400f10c0
// Address  : 0x400f10c0
// Size     : 45 bytes


void FUN_400f10c0(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  uVar1 = FUN_40184778();
  iVar2 = FUN_400f0f40(param_1,param_2,uVar1);
  if (iVar2 == 0) {
    FUN_400f0a38(param_1);
  }
  return;
}

