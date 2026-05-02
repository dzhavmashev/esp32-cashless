// Function : FUN_400d8498
// Address  : 0x400d8498
// Size     : 948 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d8498(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 in_PRID;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined1 auStack_58 [20];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar9 = rsr(in_PRID);
  FUN_400f06a4(0x3ffc5490,"l retry",uVar9 >> 0xd & 1);
  iVar2 = FUN_400f1a9c();
  uStack_8c = iVar2 - 290000;
  FUN_400db27c(0x3ffc4218);
  FUN_400dae70(0x3ffc4218);
  FUN_400f0780(0x3ffc5490,"ore %d\n");
  uVar10 = 0;
  uVar7 = 0;
  uVar9 = 0;
  uStack_84 = 0;
  uStack_94 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_98 = 0;
  do {
    memw();
    bVar1 = *(byte *)(param_1 + 0x54);
    if (bVar1 == 0) goto LAB_400d8805;
    uVar3 = FUN_400f1a9c();
    uVar8 = uVar7;
    if ((uVar9 == 0) && (99 < uVar3 - uStack_98)) {
      FUN_400db27c(0x3ffc4218);
      iVar2 = FUN_400da4f0(0x3ffc4218);
      uVar5 = _DAT_3ffc4a98;
      uStack_98 = uVar3;
      if (iVar2 == 0) {
        uVar4 = FUN_400efe4c(0x3ffc53f4);
        FUN_400f06a4(0x3ffc5490," Core 0",uVar5,uVar4);
        FUN_400e7730(*(undefined4 *)(param_1 + 0x18),2);
        uVar8 = 0;
        uVar9 = (uint)bVar1;
        uVar10 = uVar3;
      }
    }
    uVar7 = uVar8;
    if (uVar3 < uVar10) {
      if (uVar9 == 0) goto LAB_400d86e0;
    }
    else {
      if (uVar9 != 0) {
        uVar9 = FUN_400da2bc(*(undefined4 *)(param_1 + 0xc));
        if (uVar9 == 0) {
          FUN_400f0780(0x3ffc5490,"ection\n");
          memw();
          *(undefined1 *)(param_1 + 0x55) = 1;
          func_0x40091e4c(*(undefined4 *)(param_1 + 0x58),0,0,2,0);
          while (memw(), *(char *)(param_1 + 0x54) != '\0') {
            func_0x4009183c(0x32);
          }
          goto LAB_400d8805;
        }
        uVar7 = uVar8 + 1;
        FUN_400f06a4(0x3ffc5490,"nection",uVar7);
        iVar2 = FUN_400daf88(0x3ffc4218);
        if (iVar2 == 0) {
          uVar10 = 5000 << 0x20 - (0x20 - ((uVar8 < 3) * uVar8 + (uint)(uVar8 >= 3) * 3 & 0x1f));
          uVar10 = uVar3 + (uVar10 < 30000) * uVar10 + (uint)(uVar10 >= 30000) * 30000;
          FUN_400f06a4(0x3ffc5490,"ssfully");
          if (9 < uVar7) {
            FUN_400f0780(0x3ffc5490,"%lu ms\n");
            FUN_400f1ab4(1000);
            FUN_400efe2c(0x3ffc53f4);
          }
          goto LAB_400d875b;
        }
        FUN_400f0780(0x3ffc5490,"pt #%d\n");
        FUN_400d7378(auStack_78,0x200,0);
        uVar5 = FUN_400d4db0(auStack_58,"offline status",auStack_70);
        FUN_400d6da8("ssfully",uVar5);
        FUN_400e6d7c(auStack_44,*(undefined4 *)(param_1 + 0x1c));
        uVar5 = FUN_400d4db0(auStack_58,"",auStack_70);
        FUN_40183db8(auStack_44,uVar5,auStack_70);
        FUN_400f0a50(auStack_44);
        uVar5 = FUN_400d4db0(auStack_58,"loading firmware",auStack_70);
        FUN_400d6da8("version",uVar5);
        iVar2 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_1 + 8));
        pcVar6 = "g state";
        if (iVar2 != 1) {
          pcVar6 = "te";
        }
        uVar5 = FUN_400d4db0(auStack_58,"eviceId",auStack_70);
        FUN_400d6da8(pcVar6,uVar5);
        FUN_400f0be8(auStack_34,&DAT_3f42161d);
        FUN_400d5948(auStack_58,auStack_34);
        FUN_400da510(0x3ffc4218,auStack_34);
        FUN_400f0a50(auStack_34);
        FUN_400d73a8(auStack_78);
        FUN_400e7730(*(undefined4 *)(param_1 + 0x18),5);
        uVar7 = 0;
      }
LAB_400d86e0:
      if (999 < uVar3 - uStack_90) {
        FUN_400e6198(0x3ffc4ae8);
        uStack_90 = uVar3;
      }
      if (299999 < uVar3 - uStack_8c) {
        FUN_400e76c0(*(undefined4 *)(param_1 + 0x24));
        uStack_8c = uVar3;
      }
      uVar9 = 0;
    }
LAB_400d875b:
    if (0x31 < uVar3 - uStack_94) {
      FUN_400e7850(*(undefined4 *)(param_1 + 0x18));
      if (*(char *)(param_1 + 0x2c) != '\0') {
        FUN_400e6478(0x3ffc4cec);
      }
      uStack_94 = uVar3;
      if (*(int **)(param_1 + 0x28) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x28) + 0x20))();
      }
    }
    if (299999 < uVar3 - uStack_84) {
      FUN_400d6e9c(param_1);
      uStack_84 = uVar3;
    }
    if (((uVar9 == 0) && (299999 < uVar3 - uStack_88)) &&
       (iVar2 = FUN_400da2bc(*(undefined4 *)(param_1 + 0xc)), uStack_88 = uVar3, iVar2 == 0)) {
      FUN_400f0780(0x3ffc5490,"booting");
      memw();
      *(undefined1 *)(param_1 + 0x55) = 1;
      func_0x40091e4c(*(undefined4 *)(param_1 + 0x58),0,0,2,0);
      while (memw(), *(char *)(param_1 + 0x54) != '\0') {
        func_0x4009183c(0x32);
      }
LAB_400d8805:
      FUN_400f0780(0x3ffc5490,"on lost");
      func_0x40091740(0);
      iVar2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
      FUN_400f0a50(auStack_34);
      do {
        FUN_400d73a8(auStack_78);
        thunk_FUN_401710d8(iVar2);
      } while( true );
    }
    func_0x4009183c(10);
  } while( true );
}

