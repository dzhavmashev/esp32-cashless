// Function : FUN_400db35c
// Address  : 0x400db35c
// Size     : 331 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400db35c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 ****ppppuVar5;
  undefined4 ***local_54 [3];
  byte bStack_45;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  param_2 = param_2 & 0xff;
  memw();
  iStack_24 = _DAT_3ffc5708;
  *(uint *)(param_1 + 0x880) = param_2;
  FUN_400db344(param_1 + 0x830);
  FUN_400f0be8(local_54,&DAT_3f42161d);
  if (param_2 == 4) {
    pcVar4 = "ailable";
LAB_400db3d0:
    FUN_400f0d70(local_54,pcVar4);
    uVar3 = 3;
  }
  else {
    if (param_2 < 5) {
      if (param_2 == 2) {
        pcVar4 = "horized";
        goto LAB_400db3d0;
      }
      pcVar4 = "erprint";
      if ((param_2 < 3) && (pcVar4 = "entials", param_2 != 1)) {
LAB_400db3a1:
        pcVar4 = "version";
      }
    }
    else {
      if (param_2 == 6) {
        FUN_400f0d70(local_54,"ejected");
        uVar3 = 4;
        goto LAB_400db3be;
      }
      if (param_2 < 6) {
        pcVar4 = "nnected";
        goto LAB_400db3d0;
      }
      if (param_2 != 7) goto LAB_400db3a1;
      pcVar4 = ": \'%s\'\n";
    }
    FUN_400f0d70(local_54,pcVar4);
    uVar3 = 5;
  }
LAB_400db3be:
  FUN_400f0be8(auStack_34," reason");
  FUN_400f0dd0(auStack_44,*(undefined4 *)(param_1 + 0x880),10);
  uVar2 = FUN_400f10c0(auStack_34,auStack_44);
  uVar2 = FUN_400f10f0(uVar2,") 0 ) ) )");
  FUN_400f0fa0(local_54,uVar2);
  FUN_400f0a50(auStack_44);
  FUN_400f0a50(auStack_34);
  *(int *)(param_1 + 0x808) = *(int *)(param_1 + 0x808) + 1;
  FUN_400da604(param_1,uVar3,local_54);
  ppppuVar5 = local_54;
  if ((bStack_45 & 0x80) == 0) {
    ppppuVar5 = (undefined4 ****)local_54[0];
  }
  FUN_400f06a4(0x3ffc5490,"eason: ",ppppuVar5);
  FUN_400f0a50(local_54);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_44);
    do {
      FUN_400f0a50(auStack_34);
      FUN_400f0a50(local_54);
      thunk_FUN_401710d8(iVar1);
    } while( true );
  }
  return;
}

