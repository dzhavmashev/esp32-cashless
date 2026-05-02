// Function : FUN_400ede1c
// Address  : 0x400ede1c
// Size     : 507 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ede1c(int param_1,undefined4 param_2,undefined4 param_3,char param_4,char param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_64,"tocol\r\n");
  iVar2 = FUN_400f122c(param_2,auStack_64);
  if (iVar2 == 0) {
    FUN_400f0be8(auStack_54,"on/json");
    iVar2 = FUN_400f122c(param_2,auStack_54);
    bVar1 = false;
    if (iVar2 == 0) {
      FUN_400f0be8(auStack_44,"nection");
      iVar2 = FUN_400f122c(param_2,auStack_44);
      bVar1 = false;
      if (iVar2 == 0) {
        FUN_400f0be8(auStack_34,"on");
        iVar2 = FUN_400f122c(param_2,auStack_34);
        bVar1 = true;
        if (iVar2 != 0) {
          iVar2 = (*(code *)&LAB_40183a7b_1)(param_1 + 0x6c);
          bVar1 = iVar2 == 0;
        }
        FUN_400f0a50(auStack_34);
      }
      FUN_400f0a50(auStack_44);
    }
    FUN_400f0a50(auStack_54);
  }
  else {
    bVar1 = false;
  }
  FUN_400f0a50(auStack_64);
  if (!bVar1) goto LAB_400ee042;
  FUN_400f0d4c(auStack_64,param_2);
  FUN_400f1050(auStack_64,"(%04X)");
  param_1 = param_1 + 0x4c;
  if (((param_5 != '\0') && (iVar2 = FUN_400f143c(param_1,auStack_64), iVar2 != -1)) &&
     ((iVar2 == 0 || (pcVar4 = (char *)FUN_400f1354(param_1,iVar2 + -1), *pcVar4 == '\n')))) {
    iVar3 = FUN_400f13c0(param_1,10,iVar2);
    FUN_400f1520(auStack_54,param_1,0,iVar2);
    FUN_400f0d4c(auStack_34,auStack_54);
    FUN_400ed9cc(auStack_44,param_1,iVar3 + 1);
    uVar5 = FUN_400f10c0(auStack_34,auStack_44);
    FUN_400f0d18(param_1,uVar5);
    FUN_400f0a50(auStack_44);
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(auStack_54);
  }
  FUN_400f0fa0(auStack_64,param_3);
  FUN_400f1050(auStack_64,"ggered\r\n\r\n");
  if (param_4 == '\0') goto LAB_400ee059;
  FUN_400f0d4c(auStack_34,auStack_64);
  uVar5 = FUN_400f10c0(auStack_34,param_1);
  FUN_400f0d18(param_1,uVar5);
  FUN_400f0a50(auStack_34);
  while( true ) {
    FUN_400f0a50(auStack_64);
LAB_400ee042:
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400ee059:
    FUN_400f0fa0(param_1);
  }
  return;
}

