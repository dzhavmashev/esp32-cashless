// Function : FUN_400f0e84
// Address  : 0x400f0e84
// Size     : 123 bytes


void FUN_400f0e84(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  FUN_400f0a18(param_1);
  iVar1 = func_0x40094d68(param_3 + 0x2a);
  if (iVar1 == 0) {
    FUN_400f0d70(param_1,&PTR_LAB_3f40a584);
    uVar4 = func_0x40085c04();
    uVar2 = FUN_401847ec(&DAT_3f40a588);
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),1000,0);
    FUN_4012105c("ing.cpp",uVar3,uVar2,0x6f,"tion.\r\n");
  }
  else {
    uVar4 = (*(code *)&SUB_40002c34)(param_2);
    uVar2 = FUN_400f3190((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),param_3 + 2,param_3,iVar1);
    FUN_400f0d70(param_1,uVar2);
    func_0x40094d88(iVar1);
  }
  return;
}

