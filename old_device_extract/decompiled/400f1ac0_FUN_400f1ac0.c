// Function : FUN_400f1ac0
// Address  : 0x400f1ac0
// Size     : 373 bytes


void FUN_400f1ac0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int aiStack_24 [9];
  
  iVar1 = FUN_401847dc();
  if (iVar1 == 0) {
    uVar2 = FUN_400f7f5c();
    iVar1 = FUN_400f82a4(uVar2,aiStack_24);
    if ((iVar1 == 0) && (aiStack_24[0] == 1)) {
      iVar1 = FUN_401847d4();
      if (iVar1 == 0) {
        uVar5 = func_0x40085c04();
        uVar2 = FUN_401847ec("pinMode");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
        FUN_4012105c("o WDT\r\n",uVar4,uVar2,0xe9,"r: %u\r\n");
        FUN_400f8298();
      }
      else {
        FUN_400f828c();
      }
    }
  }
  FUN_400f33e8(0xf0);
  FUN_400f1c48();
  (*(code *)&LAB_4018e556_2)("me",1);
  iVar1 = FUN_400f947c();
  if ((iVar1 == 0x110d) || (iVar1 == 0x1110)) {
    iVar3 = FUN_400f8eb4(1,2,0);
    if (iVar3 == 0) {
      uVar5 = func_0x40085c04();
      uVar2 = FUN_401847ec("pinMode");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
      FUN_4012105c("tion!\r\n",uVar4,uVar2,0x104,"r: %u\r\n");
      goto LAB_400f1b39;
    }
    iVar1 = FUN_400f9018(iVar3,0,*(undefined4 *)(iVar3 + 0x10));
    if (iVar1 == 0) {
      iVar1 = FUN_400f947c();
      goto LAB_400f1b39;
    }
    uVar5 = func_0x40085c04();
    uVar2 = FUN_401847ec("pinMode");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    FUN_4012105c("n ...\r\n",uVar4,uVar2,0x101,"r: %u\r\n");
  }
  else {
LAB_400f1b39:
    if (iVar1 == 0) goto LAB_400f1b3c;
  }
  uVar5 = func_0x40085c04();
  uVar2 = FUN_401847ec("pinMode");
  uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
  FUN_4012105c("ition\r\n",uVar4,uVar2,0x108,"r: %u\r\n",iVar1);
LAB_400f1b3c:
  iVar1 = FUN_401847e4();
  if (iVar1 == 0) {
    FUN_4011ff74(3);
  }
  FUN_401847cc();
  FUN_401847c4();
  return;
}

