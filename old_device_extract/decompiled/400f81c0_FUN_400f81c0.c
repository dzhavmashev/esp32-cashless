// Function : FUN_400f81c0
// Address  : 0x400f81c0
// Size     : 195 bytes


int FUN_400f81c0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 auStack_60 [6];
  int aiStack_48 [18];
  
  iVar1 = FUN_400f7e98(auStack_60);
  if (iVar1 == 0) {
    iVar4 = 0x105;
    goto LAB_400f8200;
  }
  uVar2 = FUN_400f84a4(auStack_60);
  if ((uVar2 == 0xffffffff) || (iVar4 = FUN_400f7fd0(), iVar4 == 0)) {
LAB_400f8268:
    uVar3 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"_length"," slots\n",uVar3,"_length");
    iVar4 = -1;
  }
  else {
    if (param_1 == 0) {
      iVar4 = FUN_400f810c();
      if (iVar4 == 0) {
        uVar3 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"_length","!= NULL",uVar3,"_length");
        iVar4 = 0x1505;
        goto LAB_400f8200;
      }
      aiStack_48[uVar2 * 8] = 3;
      if ((uVar2 & 0xff) < 2) {
        memw();
        iVar4 = FUN_400f7f24(auStack_60,auStack_60[uVar2 * 8],uVar2 & 0xff,iVar1);
        if (iVar4 != 0) goto LAB_400f8200;
        (*(code *)&SUB_40082ea4)();
        goto LAB_400f8268;
      }
    }
    else {
      iVar4 = 0;
      if (aiStack_48[uVar2 * 8] == 2) goto LAB_400f8200;
      aiStack_48[uVar2 * 8] = 2;
      if ((uVar2 & 0xff) < 2) {
        iVar4 = FUN_400f7f24(auStack_60,auStack_60[uVar2 * 8],uVar2 & 0xff,iVar1);
        goto LAB_400f8200;
      }
    }
    iVar4 = 0x102;
  }
LAB_400f8200:
  memw();
  return iVar4;
}

