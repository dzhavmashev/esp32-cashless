// Function : FUN_40127c64
// Address  : 0x40127c64
// Size     : 737 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40127c64(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puStack_54c;
  undefined4 uStack_548;
  undefined1 auStack_544 [64];
  undefined1 auStack_504 [64];
  undefined1 auStack_4c4 [32];
  undefined1 auStack_4a4 [128];
  undefined1 auStack_424 [512];
  undefined1 auStack_224 [512];
  int local_24;
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(auStack_424,0,0x200);
  iVar2 = *(int *)(param_1 + 0x48);
  if (iVar2 != 0) goto LAB_40127cb1;
LAB_40127c91:
  param_1 = -1;
  do {
    iVar2 = _DAT_3ffc5708;
    memw();
    memw();
    if (local_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_40127cb1:
    if (*(int *)(iVar2 + 0x40) != 0) {
      iVar2 = FUN_40128d44();
      if ((((iVar2 == 0) ||
           (iVar4 = FUN_40128e70(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),
                                 *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x34),
                                 *(undefined4 *)(param_1 + 0x38),iVar2), iVar4 < 0)) ||
          (iVar4 = FUN_40128e34(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar2,
                                *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x30),iVar2), iVar4 < 0))
         || ((iVar4 = FUN_40128e70(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar2,
                                   *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x3c),iVar2),
             iVar4 < 0 ||
             (iVar4 = FUN_40128ff8(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar2),
             iVar4 != 0)))) {
        iVar4 = -1;
      }
      else {
        iVar4 = FUN_40128d98(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),iVar2,auStack_424,0);
        iVar4 = iVar4 >> 0x1f;
      }
      FUN_40128d84(iVar2,1);
      if (iVar4 == -1) goto LAB_40127c91;
    }
    if (*(int *)(*(int *)(param_1 + 0x48) + 0x48) != 0) {
      iVar2 = FUN_40128a18();
      if (((iVar2 == 0) ||
          (iVar4 = FUN_40128b08(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x38),
                                *(undefined4 *)(param_1 + 0x38),
                                *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),iVar2), iVar4 < 0))
         || ((iVar4 = FUN_40128b74(iVar2,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x2c),
                                   *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),iVar2),
             iVar4 < 0 ||
             ((iVar4 = FUN_40128b08(iVar2,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x3c),
                                    *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),iVar2),
              iVar4 < 0 || (iVar4 = FUN_40128c2c(iVar2), iVar4 != 0)))))) {
        iVar4 = -1;
      }
      else {
        iVar4 = FUN_40128a90(iVar2,auStack_424,0x200,
                             *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44));
        iVar4 = iVar4 >> 0x1f;
      }
      FUN_40128a7c(iVar2,1);
      if (iVar4 == -1) goto LAB_40127c91;
    }
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44);
    iVar2 = FUN_40128a18();
    if (iVar2 == 0) {
LAB_40127ccd:
      iVar3 = 0;
      iVar4 = -1;
    }
    else {
      if ((*(byte *)(param_1 + 0x50) & 1) == 0) {
        iVar5 = 0x20;
LAB_40127e03:
        (*(code *)&SUB_4008b530)(auStack_544,0,iVar5);
        iVar3 = 0;
        puVar8 = auStack_544;
        iVar1 = iVar5;
      }
      else {
        iVar4 = *(int *)(param_1 + 0x48);
        if (*(int *)(iVar4 + 0x48) == 0) {
          iVar1 = FUN_401857b8(uVar7);
        }
        else {
          iVar1 = FUN_401857d0();
        }
        iVar6 = *(int *)(iVar4 + 100);
        iVar4 = *(int *)(iVar4 + 0x68);
        if (iVar6 == 0) {
          iVar3 = 0;
          iVar5 = iVar1;
          if (iVar4 == 0) goto LAB_40127e03;
LAB_40127e26:
          iVar3 = iVar3 + *(int *)(iVar4 + 4);
        }
        else {
          iVar3 = *(int *)(iVar6 + 4);
          if (iVar4 != 0) goto LAB_40127e26;
        }
        memw();
        iVar3 = FUN_401052d0(iVar3);
        if (iVar3 == 0) goto LAB_40127ccd;
        if ((*(byte *)(*(int *)(param_1 + 0x48) + 0x6c) & 1) == 0) {
          iVar5 = iVar6;
          if (iVar4 != 0) {
            FUN_40127190(iVar3,iVar4);
          }
        }
        else {
          iVar5 = iVar4;
          if (iVar6 != 0) {
            FUN_40127190(iVar3,iVar6);
          }
        }
        if (iVar5 != 0) {
          FUN_40127190(iVar3,iVar5);
        }
        puVar8 = *(undefined1 **)(iVar3 + 8);
        iVar5 = *(int *)(iVar3 + 4);
      }
      puStack_54c = auStack_424;
      iVar4 = -1;
      uStack_548 = uVar7;
      if (iVar1 == 0x20) {
        memw();
        iVar1 = FUN_401020e4(puVar8,iVar5,1,&puStack_54c,&uStack_548,auStack_504);
        iVar4 = -1;
        if (-1 < iVar1) {
          iVar1 = FUN_40128ad8(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x20),
                               *(undefined4 *)(param_1 + 0x38),iVar2);
          iVar4 = -1;
          if (-1 < iVar1) {
            iVar1 = FUN_40128af0(iVar2,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x50),iVar2);
            iVar4 = -1;
            if (-1 < iVar1) {
              FUN_40128a90(iVar2,auStack_224,0x200,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x60))
              ;
              memw();
              iVar1 = FUN_40101ce8(auStack_504,0x20,"t u2 P2",auStack_224,
                                   *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x60),auStack_4c4,0x40
                                  );
              iVar4 = -1;
              if (-1 < iVar1) {
                FUN_40102884(auStack_504,0x40);
                (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_1 + 0x48),auStack_4c4,0x20);
                (*(code *)&SUB_4008b3d0)(param_1 + 6,auStack_4a4,0x20);
                (*(code *)&SUB_4008b3d0)(param_1 + 0x26,auStack_224,0x10);
                FUN_40102884(auStack_4c4,0xa0);
                iVar4 = 0;
              }
            }
          }
        }
      }
    }
    param_1 = iVar4;
    FUN_4010531c(iVar3);
    FUN_40128a7c(iVar2,0);
  } while( true );
}

