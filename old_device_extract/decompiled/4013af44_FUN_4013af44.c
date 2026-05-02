// Function : FUN_4013af44
// Address  : 0x4013af44
// Size     : 300 bytes


undefined4
FUN_4013af44(int param_1,uint param_2,undefined4 param_3,uint param_4,undefined1 *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iStack_28;
  undefined4 auStack_24 [9];
  
  iStack_28 = 0;
  auStack_24[0] = 0;
  if (param_1 == 0) {
    if (param_4 < param_2) {
      return 0xffffbf80;
    }
    uVar5 = param_4 - param_2;
  }
  else {
    memw();
    iVar2 = FUN_40138f28(param_1);
    if (iVar2 == 0) {
      return 0xffffbf80;
    }
    iVar3 = FUN_401395dc(param_1,auStack_24,&iStack_28);
    if (iVar3 != 0) {
      return 0xffffbf80;
    }
    param_2 = FUN_401864c4(iVar2);
    iVar2 = param_2 + iStack_28;
    if (0x7f < iVar2 + 8U) {
      return 0xffffbf80;
    }
    if (iVar2 + 10U < param_2 + 10) {
      return 0xffffbf80;
    }
    uVar5 = (param_4 - 10) - iVar2;
    if (param_4 < iVar2 + 10U) {
      return 0xffffbf80;
    }
  }
  if (10 < uVar5) {
    *param_5 = 0;
    param_5[1] = 1;
    memw();
    memw();
    iVar3 = (*(code *)&SUB_4008b530)(param_5 + 2,0xff,uVar5 - 3);
    iVar2 = iStack_28;
    puVar4 = (undefined1 *)(iVar3 + (uVar5 - 3));
    *puVar4 = 0;
    memw();
    if (param_1 == 0) {
      memw();
      (*(code *)&SUB_4008b3d0)(puVar4 + 1,param_3,param_2);
      return 0;
    }
    puVar4[1] = 0x30;
    memw();
    cVar1 = (char)iStack_28;
    puVar4[3] = 0x30;
    puVar4[2] = (char)param_2 + cVar1 + '\b';
    puVar4[4] = cVar1 + '\x04';
    puVar4[5] = 6;
    puVar4[6] = cVar1;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puVar4 + 7,auStack_24[0],iStack_28);
    puVar4 = puVar4 + 7 + iVar2;
    *puVar4 = 5;
    memw();
    puVar4[2] = 4;
    puVar4[1] = 0;
    memw();
    puVar4[3] = (char)param_2;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puVar4 + 4,param_3,param_2);
    if (param_5 + param_4 == puVar4 + 4 + param_2) {
      return 0;
    }
    FUN_4013ae54(param_5,param_4);
  }
  return 0xffffbf80;
}

