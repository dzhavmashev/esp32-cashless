// Function : FUN_400ed450
// Address  : 0x400ed450
// Size     : 386 bytes


undefined4
FUN_400ed450(undefined1 *param_1,uint param_2,int param_3,undefined4 param_4,char param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0xac) = param_4;
  param_1[0xb0] = param_5 != '\0';
  FUN_400ed41c(param_1);
  *param_1 = 0;
  FUN_400f0d18(param_1 + 0x34,0x3ffc54e4);
  func_0x4008b538(param_1 + 0x44,0,0x68);
  if (param_2 == 0) {
    *param_1 = 5;
    return 0;
  }
  if (param_3 == 0) {
    iVar1 = FUN_400f80b4(0);
    *(int *)(param_1 + 0x30) = iVar1;
  }
  else {
    if (param_3 != 100) {
      *param_1 = 0xb;
      uVar5 = func_0x40085c04();
      uVar2 = FUN_401847ec("Aborted");
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
      FUN_4012105c("ter.cpp",uVar3,uVar2,0x9b,"eBuffer",param_3);
      return 0;
    }
    iVar1 = FUN_400f8eb4(1,0x82,param_6);
    *(int *)(param_1 + 0x30) = iVar1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (iVar1 != 0) goto LAB_400ed528;
    iVar1 = FUN_400f8eb4(1,0x81,0);
    *(int *)(param_1 + 0x30) = iVar1;
    *(undefined4 *)(param_1 + 0x28) = 0x1000;
  }
  if (iVar1 == 0) {
    *param_1 = 10;
    return 0;
  }
LAB_400ed528:
  uVar4 = *(uint *)(*(int *)(param_1 + 0x30) + 0x10);
  if ((param_2 != 0xffffffff) &&
     (uVar4 = param_2, *(uint *)(*(int *)(param_1 + 0x30) + 0x10) < param_2)) {
    *param_1 = 5;
    uVar5 = func_0x40085c04();
    uVar2 = FUN_401847ec("Aborted");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    FUN_4012105c("nd %u\r\n",uVar3,uVar2,0xa3,"eBuffer",param_2,
                 *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x10));
    return 0;
  }
  iVar1 = func_0x40094d68(0x1000);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    *(uint *)(param_1 + 0x10) = uVar4;
    *(int *)(param_1 + 0x2c) = param_3;
    FUN_400f05f0(param_1 + 0x44);
    return 1;
  }
  uVar5 = func_0x40085c04();
  uVar2 = FUN_401847ec("Aborted");
  uVar3 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
  FUN_4012105c(" > %u\r\n",uVar3,uVar2,0xaa,"eBuffer");
  return 0;
}

