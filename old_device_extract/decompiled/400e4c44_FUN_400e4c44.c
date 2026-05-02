// Function : FUN_400e4c44
// Address  : 0x400e4c44
// Size     : 847 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e4c44(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 ****ppppuVar9;
  int iVar10;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(char *)(param_1 + 0x201) != '\0') goto LAB_400e4e95;
  *(undefined1 *)(param_1 + 0x201) = 1;
  iVar10 = param_1 + 0x3c;
  if ((*(byte *)(param_1 + 0x4b) & 0x80) == 0) {
    iVar10 = *(int *)(param_1 + 0x3c);
  }
  FUN_400f06a4(0x3ffc5490,"oo soon",iVar10);
  iVar10 = FUN_400e4a44(param_1,*(undefined4 *)(param_1 + 0x9c));
  if (iVar10 == 0) {
    FUN_400f0be8(auStack_34,"ion %s\n");
    FUN_400e4a64(param_1,8,auStack_34);
    uVar6 = 1;
  }
  else {
    uVar6 = FUN_400efe4c(0x3ffc53f4);
    if (49999 < uVar6) {
      iVar10 = FUN_400f80b4(0);
      uVar8 = 0;
      if (iVar10 != 0) {
        uVar8 = *(undefined4 *)(iVar10 + 0x10);
      }
      FUN_400f06a4(0x3ffc5490," memory",uVar8,*(undefined4 *)(param_1 + 0x9c));
      iVar5 = FUN_400ed450(0x3ffc5340,*(undefined4 *)(param_1 + 0x9c),0,0xffffffff,0);
      iVar10 = 0x3ffc5490;
      uVar6 = 0x3ffc5340;
      if (iVar5 != 0) goto LAB_400e4de1;
      FUN_400f0be8(local_44," bytes\n");
      uVar1 = FUN_400ed644(0x3ffc5340);
      FUN_400f1050(local_44,uVar1);
      FUN_400f1050(local_44,"date - ");
      FUN_400f1084(local_44,*(undefined4 *)(param_1 + 0x9c));
      FUN_400f1050(local_44,"(size: ");
      FUN_400f1084(local_44,uVar8);
      FUN_400f1050(local_44,"ition: ");
      uVar6 = (uint)bStack_35;
      ppppuVar9 = local_44;
      if ((bStack_35 & 0x80) == 0) {
        ppppuVar9 = (undefined4 ****)local_44[0];
      }
      FUN_400f06a4(0x3ffc5490," bytes)",ppppuVar9);
      ppppuVar9 = local_44;
      if ((bStack_35 & 0x80) == 0) {
        ppppuVar9 = (undefined4 ****)local_44[0];
      }
      FUN_400f0be8(auStack_34,ppppuVar9);
      FUN_400e4a64(param_1,9,auStack_34);
      FUN_400f0a50(auStack_34);
      FUN_400e4b9c(param_1,7);
      FUN_400f0a50(local_44);
      goto LAB_400e4dc9;
    }
    FUN_400f0be8(auStack_34," update");
    FUN_400e4a64(param_1,8,auStack_34);
    uVar6 = 49999;
  }
  FUN_400f0a50(auStack_34);
LAB_400e4cd9:
  uVar8 = 7;
  do {
    FUN_400e4b9c(param_1,uVar8);
LAB_400e4dc9:
    do {
      do {
        iVar10 = iStack_24;
        param_1 = _DAT_3ffc5708;
        memw();
        memw();
        if (iStack_24 == _DAT_3ffc5708) {
          return;
        }
        func_0x40082ecc();
LAB_400e4de1:
        FUN_400f0780(iVar10,"TA] %s\n");
        uVar8 = *(undefined4 *)(param_1 + 0x1bc);
        FUN_400f0d4c(auStack_34,param_1 + 0x7c);
        iVar5 = param_1 + 0xfc;
        FUN_400edcd8(iVar5,uVar8,auStack_34);
        FUN_400f0a50(auStack_34);
        FUN_400eddd4(iVar5,30000);
        iVar10 = FUN_400efdd4(iVar5);
        if (iVar10 != 200) {
          FUN_400f0be8(auStack_34,"d proxy");
          FUN_400f0dd0(local_44,iVar10,10);
          uVar8 = FUN_400f10c0(auStack_34,local_44);
          FUN_400e4a64(param_1,2,uVar8);
          FUN_400f0a50(local_44);
          FUN_400f0a50(auStack_34);
          FUN_400eda70(iVar5);
          uVar3 = uVar6;
LAB_400e4e7b:
          FUN_400ed5d8(uVar3);
          goto LAB_400e4cd9;
        }
        *(undefined4 *)(param_1 + 0x4c) = 0;
        *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x9c);
        *(undefined4 *)(param_1 + 0x1f0) = 0xbf800000;
LAB_400e4e95:
        uVar6 = param_1 + 0xfc;
        piVar2 = (int *)FUN_400ede04(uVar6);
        if (piVar2 == (int *)0x0) {
          FUN_400f0be8(auStack_34,"omplete");
          FUN_400e4a64(param_1,2,auStack_34);
          FUN_400f0a50(auStack_34);
          FUN_400eda70(uVar6);
          uVar3 = 0x3ffc5340;
          goto LAB_400e4e7b;
        }
        uVar3 = (**(code **)(*piVar2 + 0x18))();
      } while ((uVar3 == 0) ||
              (iVar10 = (**(code **)(*piVar2 + 0x28))
                                  (piVar2,*(undefined4 *)(param_1 + 500),
                                   (uVar3 < 0x4000) * uVar3 + (uint)(uVar3 >= 0x4000) * 0x4000),
              iVar10 < 1));
      iVar5 = FUN_400ed920(0x3ffc5340,*(undefined4 *)(param_1 + 500),iVar10);
      if (iVar10 != iVar5) {
        FUN_400f0be8(auStack_34,"ailed: ");
        FUN_400e4a64(param_1,9,auStack_34);
        FUN_400f0a50(auStack_34);
        FUN_400eda70(uVar6);
        uVar3 = 0x3ffc5340;
        goto LAB_400e4e7b;
      }
      uVar3 = iVar10 + *(int *)(param_1 + 0x4c);
      uVar7 = *(uint *)(param_1 + 0x50);
      *(uint *)(param_1 + 0x4c) = uVar3;
      fVar4 = (float)FUN_40187018((float)uVar3 / 1.0,(float)uVar7 / 1.0);
      *(float *)(param_1 + 0x54) = fVar4 * 100.0;
    } while (uVar3 < uVar7);
    FUN_400f0780(0x3ffc5490,"re data");
    FUN_400eda70(uVar6);
    uVar8 = 4;
  } while( true );
}

