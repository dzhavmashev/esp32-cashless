// Function : FUN_400f93a4
// Address  : 0x400f93a4
// Size     : 100 bytes


int FUN_400f93a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  int *piStack_28;
  uint auStack_24 [9];
  
  FUN_400f9390();
  iVar1 = FUN_400f9350(param_1,&piStack_28);
  if ((iVar1 != 0) ||
     (iVar1 = (**(code **)(*piStack_28 + 0x18))(piStack_28,param_2,param_3,auStack_24), iVar1 != 0))
  goto LAB_400f93d5;
  if (param_5 != (uint *)0x0) {
    if (param_4 == 0) {
      *param_5 = auStack_24[0];
      goto LAB_400f93d5;
    }
    uVar2 = *param_5;
    *param_5 = auStack_24[0];
    if (auStack_24[0] <= uVar2) {
      iVar1 = (**(code **)(*piStack_28 + 0x30))(piStack_28,param_2,param_3,param_4);
      goto LAB_400f93d5;
    }
  }
  iVar1 = 0x110c;
  memw();
LAB_400f93d5:
  memw();
  FUN_400f9378();
  return iVar1;
}

