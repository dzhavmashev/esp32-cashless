// Function : FUN_400d6844
// Address  : 0x400d6844
// Size     : 1100 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d6844(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined *puVar4;
  int *piVar5;
  undefined1 uStack_71c;
  undefined1 uStack_71b;
  undefined1 uStack_71a;
  char cStack_719;
  undefined1 auStack_698 [16];
  undefined1 auStack_688 [16];
  undefined1 auStack_678 [24];
  undefined1 auStack_660 [528];
  undefined1 auStack_450 [24];
  undefined1 auStack_438 [1044];
  int *local_24;
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"ailed: ");
  iVar1 = (*(code *)&LAB_40183a7b_1)(param_1);
  piVar3 = (int *)0x3ffc5490;
  if (iVar1 != 0) goto LAB_400d68d1;
  FUN_400f0d70(param_1 + 0x10,"n state");
  FUN_400f0be8(auStack_450,"error: ");
  uVar2 = FUN_400f10c0(auStack_450,param_1 + 0x10);
  FUN_400f0768(0x3ffc5490,uVar2);
  FUN_400f0a50(auStack_450);
  param_1 = -1;
  do {
    while( true ) {
      piVar3 = local_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (local_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400d68d1:
      iVar1 = FUN_400e6a84(0x3ffc4d78);
      if (iVar1 != 0) break;
      FUN_400f0d70(param_1 + 0x10,"ivation");
      FUN_400f0be8(auStack_450,"error: ");
      uVar2 = FUN_400f10c0(auStack_450,param_1 + 0x10);
      FUN_400f0768(piVar3,uVar2);
LAB_400d691c:
      FUN_400f0a50(auStack_450);
      param_1 = 0x191;
    }
    iVar1 = FUN_400e6ab4(0x3ffc4d78);
    if (iVar1 != 0) {
      FUN_400f0d70(param_1 + 0x10,"ivation");
      FUN_400f0be8(auStack_450,"error: ");
      uVar2 = FUN_400f10c0(auStack_450,param_1 + 0x10);
      FUN_400f0768(piVar3,uVar2);
      goto LAB_400d691c;
    }
    FUN_40183bb4(auStack_450);
    uVar2 = FUN_400d4db0(auStack_438," failed",auStack_450);
    FUN_400d3e74("version",uVar2);
    uVar2 = FUN_400d4db0(auStack_438,"nt_mode",auStack_450);
    FUN_400d3e74("n",uVar2);
    iVar1 = FUN_400d9cc8(0x3ffc4090);
    puVar4 = &DAT_3f401ac9;
    if (iVar1 == 0) {
      puVar4 = &DAT_3f401ace;
    }
    FUN_400f06a4(piVar3,&DAT_3f401ec9,puVar4);
    if (iVar1 == 0) {
      FUN_400f0780(piVar3,"request");
      FUN_400d9b74(&uStack_71c,0x3ffc4090);
      puVar4 = &DAT_3f401ac9;
      if (cStack_719 == '\0') {
        puVar4 = &DAT_3f401ace;
      }
      FUN_400f06a4(piVar3," config",uStack_71c,uStack_71b,uStack_71a,puVar4);
    }
    else {
      FUN_400d9b74(&uStack_71c,0x3ffc4090);
      puVar4 = &DAT_3f401ac9;
      if (cStack_719 == '\0') {
        puVar4 = &DAT_3f401ace;
      }
      FUN_400f06a4(piVar3,"ty: %s\n",uStack_71c,uStack_71b,uStack_71a,puVar4);
      FUN_400d6004(auStack_688,param_1,&uStack_71c);
      FUN_40183bd4(auStack_678);
      FUN_400d5130(auStack_678,auStack_688);
      iVar1 = FUN_400d4db0(auStack_438,"xt: %s\n");
      if (iVar1 != 0) {
        FUN_400d43ec(iVar1,auStack_660,auStack_450);
      }
      FUN_400f0780(piVar3,"_config");
      FUN_400f0a50(auStack_688);
    }
    FUN_400f0be8(auStack_698,&DAT_3f42161d);
    FUN_400d5948(auStack_438,auStack_698);
    FUN_400f0780(piVar3,"xt: %s\n");
    FUN_400f0be8(auStack_678,"th mTLS");
    uVar2 = FUN_400f10c0(auStack_678,auStack_698);
    FUN_400f0768(piVar3,uVar2);
    FUN_400f0a50(auStack_678);
    FUN_400f0be8(auStack_688,&DAT_3f42161d);
    FUN_400f0be8(auStack_678,"yload: ");
    iVar1 = FUN_400d6324(param_1,auStack_678,auStack_698,auStack_688);
    FUN_400f0a50(auStack_678);
    if (iVar1 == 0) {
      FUN_400f0d70(param_1 + 0x10,"ctivate");
      FUN_400f0be8(auStack_678,"error: ");
      uVar2 = FUN_400f10c0(auStack_678,param_1 + 0x10);
      FUN_400f0768(piVar3,uVar2);
LAB_400d6c40:
      FUN_400f0a50(auStack_678);
      param_1 = -1;
    }
    else {
      FUN_400f0780(piVar3,"request");
      FUN_400f0be8(auStack_678,"esponse");
      uVar2 = FUN_400f10c0(auStack_678,auStack_688);
      FUN_400f0768(piVar3,uVar2);
      FUN_400f0a50(auStack_678);
      iVar1 = FUN_400d59bc(param_1,auStack_688,param_2);
      if (iVar1 == 0) {
        FUN_400f0d70(param_1 + 0x10,"ponse: ");
        FUN_400f0be8(auStack_678,"error: ");
        uVar2 = FUN_400f10c0(auStack_678,param_1 + 0x10);
        FUN_400f0768(piVar3,uVar2);
        goto LAB_400d6c40;
      }
      FUN_400f0780(piVar3,"esponse");
      piVar5 = param_2;
      if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
        piVar5 = (int *)*param_2;
      }
      FUN_400f06a4(piVar3,"cessful",piVar5,param_2[4]);
      param_1 = 200;
    }
    FUN_400f0a50(auStack_688);
    FUN_400f0a50(auStack_698);
  } while( true );
}

