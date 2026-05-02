// Function : FUN_400eeef0
// Address  : 0x400eeef0
// Size     : 1696 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400eeef0(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  byte extraout_var;
  byte extraout_var_00;
  int iVar3;
  undefined4 ****ppppuVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uStack_d4;
  undefined1 auStack_d0 [36];
  undefined4 ***local_ac [3];
  byte bStack_9d;
  undefined1 auStack_9c [16];
  undefined1 auStack_8c [16];
  int iStack_7c;
  undefined1 auStack_78 [16];
  undefined1 auStack_68 [16];
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  int iStack_38;
  char cStack_34;
  int iStack_30;
  char cStack_2c;
  undefined2 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(int *)(param_1 + 0xbc) == 0) goto LAB_400ef57a;
  FUN_400f0be8(auStack_8c,&DAT_3f42161d);
  FUN_400f0be8(auStack_78,&DAT_3f42161d);
  FUN_400f0be8(auStack_68,&DAT_3f42161d);
  FUN_400f0be8(auStack_58,&DAT_3f42161d);
  FUN_400f0be8(auStack_48,&DAT_3f42161d);
  iStack_38 = 0;
  cStack_34 = '\0';
  iStack_30 = 0;
  cStack_2c = '\0';
  uStack_28 = 0;
  FUN_400f0be8(local_ac,&DAT_3f42161d);
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  func_0x4008ca1c(param_2,"asic",auStack_d0);
  iStack_7c = func_0x4008b7b0(auStack_d0);
  iVar1 = FUN_400f13f0(param_3,0x3d);
  iVar2 = FUN_400f13f0(param_3,0x3b);
  if ((iVar1 < 0) || (iVar2 <= iVar1)) goto LAB_400ef56b;
  FUN_400f1520(auStack_9c,param_3,0,iVar1);
  FUN_400f0d60(auStack_78,auStack_9c);
  FUN_400f0a50(auStack_9c);
  FUN_400f1520(auStack_9c,param_3,iVar1 + 1,iVar2);
  FUN_400f0d60(auStack_68,auStack_9c);
  FUN_400f0a50(auStack_9c);
  FUN_400f17ac(param_3);
  FUN_400f0be8(auStack_9c,"H:%M:%S");
  iVar1 = FUN_400f143c(param_3,auStack_9c);
  FUN_400f0a50(auStack_9c);
  if (-1 < iVar1) {
    FUN_400f0be8(auStack_9c,"H:%M:%S");
    iVar1 = FUN_400f143c(param_3,auStack_9c);
    iVar1 = iVar1 + 8;
    FUN_400f0a50(auStack_9c);
    iVar2 = FUN_400f13c0(param_3,0x3b,iVar1);
    if (iVar1 < iVar2) {
      FUN_400f1520(auStack_9c,param_3,iVar1,iVar2);
      FUN_400f0d60(local_ac,auStack_9c);
    }
    else {
      FUN_400ed9cc(auStack_9c,param_3,iVar1);
      FUN_400f0d60(local_ac,auStack_9c);
    }
    FUN_400f0a50(auStack_9c);
    ppppuVar4 = local_ac;
    if ((bStack_9d & 0x80) == 0) {
      ppppuVar4 = (undefined4 ****)local_ac[0];
    }
    func_0x4008ca1c(ppppuVar4,"asic",auStack_d0);
    iStack_38 = func_0x4008b7b0(auStack_d0);
    cStack_34 = '\x01';
  }
  FUN_400f0be8(auStack_9c,"xpires=");
  iVar1 = FUN_400f143c(param_3,auStack_9c);
  FUN_400f0a50(auStack_9c);
  if (-1 < iVar1) {
    FUN_400f0be8(auStack_9c,"xpires=");
    iVar1 = FUN_400f143c(param_3,auStack_9c);
    iVar1 = iVar1 + 8;
    FUN_400f0a50(auStack_9c);
    iVar2 = FUN_400f13c0(param_3,0x3b,iVar1);
    if (iVar1 < iVar2) {
      FUN_400f1520(auStack_9c,param_3,iVar1,iVar2);
      FUN_400f0d60(local_ac,auStack_9c);
    }
    else {
      FUN_400ed9cc(auStack_9c,param_3,iVar1);
      FUN_400f0d60(local_ac,auStack_9c);
    }
    FUN_400f0a50(auStack_9c);
    iStack_30 = FUN_400f1854(local_ac);
    cStack_2c = '\x01';
  }
  FUN_400f0be8(auStack_9c,"ax-age=");
  iVar1 = FUN_400f143c(param_3,auStack_9c);
  FUN_400f0a50(auStack_9c);
  ppppuVar4 = (undefined4 ****)(param_1 + 0xc);
  if (iVar1 < 0) {
    iVar1 = FUN_400f14a8(ppppuVar4,0x2e);
    iVar1 = FUN_400f144c(ppppuVar4,0x2e,iVar1 + -1);
    if (iVar1 < 0) goto LAB_400ef2f7;
    FUN_400ed9cc(auStack_9c,ppppuVar4,iVar1 + 1);
    FUN_400f0d60(auStack_58,auStack_9c);
    FUN_400f0a50(auStack_9c);
  }
  else {
    FUN_400f0be8(auStack_9c,"ax-age=");
    iVar1 = FUN_400f143c(param_3,auStack_9c);
    iVar1 = iVar1 + 7;
    FUN_400f0a50(auStack_9c);
    iVar2 = FUN_400f13c0(param_3,0x3b,iVar1);
    if (iVar1 < iVar2) {
      FUN_400f1520(auStack_9c,param_3,iVar1,iVar2);
      FUN_400f0d60(local_ac,auStack_9c);
    }
    else {
      FUN_400ed9cc(auStack_9c,param_3,iVar1);
      FUN_400f0d60(local_ac,auStack_9c);
    }
    FUN_400f0a50(auStack_9c);
    iVar1 = FUN_400e6830(local_ac,"Title");
    if (iVar1 != 0) {
      FUN_400f1760(local_ac,0,1);
    }
    iVar1 = FUN_400f143c(ppppuVar4,local_ac);
    if (iVar1 < 0) goto LAB_400ef56b;
    ppppuVar4 = local_ac;
LAB_400ef2f7:
    FUN_400f0d18(auStack_58,ppppuVar4);
  }
  FUN_400f0be8(auStack_9c,"domain=");
  iVar1 = FUN_400f143c(param_3,auStack_9c);
  FUN_400f0a50(auStack_9c);
  if (-1 < iVar1) {
    FUN_400f0be8(auStack_9c,"domain=");
    iVar1 = FUN_400f143c(param_3,auStack_9c);
    iVar1 = iVar1 + 5;
    FUN_400f0a50(auStack_9c);
    iVar2 = FUN_400f13c0(param_3,0x3b,iVar1);
    if (iVar1 < iVar2) {
      FUN_400f1520(auStack_9c,param_3,iVar1,iVar2);
      FUN_400f0d60(auStack_48,auStack_9c);
    }
    else {
      FUN_400ed9cc(auStack_9c,param_3,iVar1);
      FUN_400f0d60(auStack_48,auStack_9c);
    }
    FUN_400f0a50(auStack_9c);
  }
  FUN_400f0be8(auStack_9c,"=");
  FUN_400f143c(param_3,auStack_9c);
  uStack_28 = CONCAT11(uStack_28._1_1_,(extraout_var ^ 0xff) >> 7);
  FUN_400f0a50(auStack_9c);
  FUN_400f0be8(auStack_9c,"ttponly");
  FUN_400f143c(param_3,auStack_9c);
  uStack_28 = CONCAT11((extraout_var_00 ^ 0xff) >> 7,(undefined1)uStack_28);
  FUN_400f0a50(auStack_9c);
  uStack_d4 = func_0x4008cd34(0);
  func_0x4008ad74(&uStack_d4);
  iVar2 = func_0x4008b7b0();
  iVar5 = **(int **)(param_1 + 0xbc);
  iVar1 = 0;
  while( true ) {
    puVar6 = *(undefined1 **)(param_1 + 0xbc);
    iVar3 = *(int *)(puVar6 + 4);
    if (iVar5 == iVar3) break;
    iVar3 = FUN_400f1190(iVar5 + 0x34,auStack_58);
    if (iVar3 != 0) {
      iVar3 = FUN_400f1190(iVar5 + 0x14,auStack_78);
      if (iVar3 != 0) {
        iVar1 = iVar3;
        if (cStack_2c == '\0') {
          if ((0 < iStack_30) && ((cStack_34 == '\0' || (iVar2 <= iStack_38)))) goto LAB_400ef4b9;
        }
        else if ((iVar2 <= iStack_30 + iStack_7c) && (0 < iStack_30)) {
LAB_400ef4b9:
          FUN_400f0d18(iVar5,auStack_8c);
          *(int *)(iVar5 + 0x10) = iStack_7c;
          FUN_400f0d18(iVar5 + 0x14,auStack_78);
          FUN_400f0d18(iVar5 + 0x24,auStack_68);
          FUN_400f0d18(iVar5 + 0x34,auStack_58);
          FUN_400f0d18(iVar5 + 0x44,auStack_48);
          func_0x4008b3d8(iVar5 + 0x54,&iStack_38,5);
          func_0x4008b3d8(iVar5 + 0x5c,&iStack_30,5);
          *(undefined1 *)(iVar5 + 100) = (undefined1)uStack_28;
          *(undefined1 *)(iVar5 + 0x65) = uStack_28._1_1_;
          goto LAB_400ef4cc;
        }
        FUN_400eeaf8(*(undefined4 *)(param_1 + 0xbc),iVar5);
        iVar5 = iVar5 + -0x68;
      }
    }
LAB_400ef4cc:
    iVar5 = iVar5 + 0x68;
  }
  if ((iVar1 == 0) && ((cStack_2c == '\0' || (0 < iStack_30)))) {
    if (iVar3 == *(int *)(puVar6 + 8)) goto LAB_400ef594;
    FUN_400eecf0(iVar3,auStack_8c);
    *(int *)(puVar6 + 4) = *(int *)(puVar6 + 4) + 0x68;
  }
LAB_400ef56b:
  while( true ) {
    FUN_400f0a50(local_ac);
    FUN_400ee7e0(auStack_8c);
LAB_400ef57a:
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    iVar3 = func_0x40082ecc();
    puVar6 = &DAT_3ffc5708;
LAB_400ef594:
    FUN_400eedf4(puVar6,iVar3,auStack_8c);
  }
  return;
}

