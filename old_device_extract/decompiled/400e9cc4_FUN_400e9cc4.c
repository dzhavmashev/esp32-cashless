// Function : FUN_400e9cc4
// Address  : 0x400e9cc4
// Size     : 381 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400e9cc4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined1 auStack_1bc [204];
  undefined1 auStack_f0 [140];
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_4014471c(auStack_1bc);
  iVar1 = FUN_4013acf4(auStack_f0,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = (*(code *)&LAB_401864e3_1)(auStack_f0,*(undefined4 *)(param_1 + 0x14c));
    if (iVar1 != 0) goto LAB_400e9d8c;
    uVar7 = func_0x40085c04();
    uVar2 = FUN_401847ec(&DAT_3f40931c);
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
    FUN_4012105c("or %X\r\n",uVar3,uVar2,0x3b,"undle\r\n");
    iVar1 = -1;
    goto LAB_400e9d69;
  }
  uVar7 = func_0x40085c04();
  uVar2 = FUN_401847ec(&DAT_3f40931c);
  uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
  pcVar5 = "undle.c";
  uVar6 = 0x34;
LAB_400e9d1d:
  do {
    FUN_4012105c(pcVar5,uVar3,uVar2,uVar6,"undle\r\n",iVar1);
LAB_400e9d69:
    do {
      FUN_40144730(auStack_1bc);
      param_1 = iStack_24;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return iVar1;
      }
      func_0x40082ecc();
LAB_400e9d8c:
      uVar2 = FUN_40138f28(*(undefined4 *)(param_1 + 0x148));
      iVar1 = FUN_40139210(uVar2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14),
                           auStack_64);
      if (iVar1 != 0) {
        uVar7 = func_0x40085c04();
        uVar2 = FUN_401847ec(&DAT_3f40931c);
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
        uVar6 = 0x42;
        pcVar5 = "ailed\r\n";
        goto LAB_400e9d1d;
      }
      uVar3 = *(undefined4 *)(param_1 + 0x14c);
      uVar6 = *(undefined4 *)(param_1 + 0x150);
      uVar4 = *(undefined4 *)(param_1 + 0x148);
      uVar2 = (*(code *)&LAB_401864ba_2)(uVar2);
      iVar1 = FUN_40139ce0(uVar3,uVar6,auStack_f0,uVar4,auStack_64,uVar2,
                           *(undefined4 *)(param_1 + 0x144),*(undefined4 *)(param_1 + 0x140));
    } while (iVar1 == 0);
    uVar7 = func_0x40085c04();
    uVar2 = FUN_401847ec(&DAT_3f40931c);
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
    uVar6 = 0x4a;
    pcVar5 = "or %X\r\n";
  } while( true );
}

