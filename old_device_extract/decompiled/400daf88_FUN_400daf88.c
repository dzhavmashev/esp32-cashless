// Function : FUN_400daf88
// Address  : 0x400daf88
// Size     : 710 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400daf88(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  piVar5 = (int *)(param_1 + 0x800);
  if (*piVar5 != 1) goto LAB_400dafc9;
  FUN_400f0780(0x3ffc5490," to %s\n");
  do {
    param_1 = 0;
    while( true ) {
      piVar5 = _DAT_3ffc5708;
      memw();
      memw();
      if (piStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400dafc9:
      iVar6 = param_1 + 0x7cc;
      iVar2 = FUN_400da468(iVar6);
      if (iVar2 != 0) break;
      iVar7 = param_1 + 0x7e4;
      iVar2 = FUN_400da468(iVar7);
      if (iVar2 != 0) break;
      iVar2 = FUN_400ead38(param_1);
      if (iVar2 == 0) {
        FUN_400f0780(0x3ffc5490,": \'%s\'\n");
        FUN_400ead50(param_1,1);
        iVar2 = FUN_400f1a9c();
        while ((iVar3 = FUN_400ead38(param_1), iVar3 == 0 &&
               (iVar3 = FUN_400f1a9c(), (uint)(iVar3 - iVar2) < 2000))) {
          FUN_400eb9cc(param_1);
          FUN_400f1ab4(10);
        }
      }
      FUN_400f0be8(auStack_34,"n state");
      FUN_400da604(param_1,1,auStack_34);
      FUN_400f0a50(auStack_34);
      iVar2 = FUN_400da480(param_1);
      if (iVar2 == 0) {
        FUN_400f0be8(auStack_34,"nection");
        FUN_400da604(param_1,4,auStack_34);
        iVar2 = 0;
LAB_400db1b9:
        FUN_400f0a50(auStack_34);
        param_1 = iVar2;
      }
      else {
        FUN_400f0be8(auStack_34,"LS: %s\n");
        iVar2 = param_1 + 0x860;
        uVar4 = FUN_400f10c0(auStack_34,iVar7);
        uVar4 = FUN_400f10f0(uVar4,"nnected");
        FUN_400f0d18(iVar2,uVar4);
        FUN_400f0a50(auStack_34);
        iVar3 = param_1 + 0x870;
        FUN_400f0d70(iVar3,"up mTLS");
        if ((*(byte *)((int)piVar5 + 0x6f) & 0x80) == 0) {
          iVar2 = piVar5[0x18];
        }
        if ((*(byte *)((int)piVar5 + 0x7f) & 0x80) == 0) {
          iVar3 = piVar5[0x1c];
        }
        uVar1 = func_0x4008c024(iVar3);
        *(int *)(param_1 + 0xa0) = iVar2;
        *(undefined2 *)(param_1 + 0xaa) = 0x101;
        *(int *)(param_1 + 0xa4) = iVar3;
        *(undefined2 *)(param_1 + 0xa8) = uVar1;
        if ((*(byte *)(param_1 + 0x7db) & 0x80) == 0) {
          iVar6 = *(int *)(param_1 + 0x7cc);
        }
        if ((*(byte *)(param_1 + 0x7f3) & 0x80) == 0) {
          iVar7 = *(int *)(param_1 + 0x7e4);
        }
        FUN_400f06a4(0x3ffc5490,":\"lwt\"}",iVar6,*(undefined4 *)(param_1 + 0x7dc),iVar7);
        iVar2 = FUN_400eb168(param_1);
        if (iVar2 == 0) {
          piVar5[2] = piVar5[2] + 1;
          FUN_400f0be8(auStack_34," as %s\n");
          FUN_400da604(param_1,5,auStack_34);
          goto LAB_400db1b9;
        }
        iVar6 = FUN_400f1a9c();
        while ((*piVar5 == 1 && (iVar7 = FUN_400f1a9c(), (uint)(iVar7 - iVar6) < 15000))) {
          FUN_400eb9cc(param_1);
          FUN_400f1ab4(10);
        }
        if (*piVar5 == 2) {
          FUN_400dae70(param_1);
          FUN_400f0780(0x3ffc5490,"nection");
          param_1 = iVar2;
        }
        else {
          if (*piVar5 == 1) {
            piVar5[2] = piVar5[2] + 1;
            FUN_400f0be8(auStack_34,"blished");
            FUN_400da604(param_1,5,auStack_34);
            FUN_400f0a50(auStack_34);
          }
          FUN_400f06a4(0x3ffc5490,"t (15s)",*piVar5,piVar5[2]);
          param_1 = 0;
        }
      }
    }
    if ((*(byte *)(param_1 + 0x7db) & 0x80) == 0) {
      iVar6 = *(int *)(param_1 + 0x7cc);
    }
    piVar5 = (int *)(param_1 + 0x7e4);
    if ((*(byte *)(param_1 + 0x7f3) & 0x80) == 0) {
      piVar5 = (int *)*piVar5;
    }
    FUN_400f06a4(0x3ffc5490,"rogress",iVar6,piVar5);
    FUN_400f0be8(auStack_34," ERROR: Invalid configuration");
    FUN_400da604(param_1,4,auStack_34);
    FUN_400f0a50(auStack_34);
  } while( true );
}

