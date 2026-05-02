// Function : FUN_4012b56c
// Address  : 0x4012b56c
// Size     : 378 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4012b56c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5,
                int param_6,int param_7,uint param_8)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iStack_8c;
  int iStack_84;
  undefined1 auStack_70 [12];
  undefined1 local_64 [64];
  undefined1 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  puVar6 = auStack_70;
  memw();
  FUN_40138f64(puVar6);
  iVar1 = FUN_40138f28(param_1);
  iVar3 = -0x6c00;
  uVar2 = param_5;
  if (iVar1 == 0) goto LAB_4012b660;
  memw();
  uVar2 = FUN_401864c4();
  iVar3 = (*(code *)&SUB_4008c01c)(param_4);
  iStack_84 = iVar3 + param_6 + uVar2;
  memw();
  puVar4 = (undefined1 *)FUN_4013ae30(1,iStack_84);
  iVar5 = -0x7f00;
  if (puVar4 == (undefined1 *)0x0) goto LAB_4012b640;
  iStack_8c = (*(code *)&SUB_4008c01c)(param_4);
  memw();
  (*(code *)&SUB_4008b3d0)(puVar4 + uVar2,param_4,iStack_8c);
  (*(code *)&SUB_4008b3d0)(puVar4 + uVar2 + iStack_8c,param_5,param_6);
  iVar5 = FUN_4013905c(puVar6,iVar1,1);
  if (iVar5 != 0) goto LAB_4012b640;
  iVar5 = FUN_40139270(puVar6,param_2,param_3);
  if (iVar5 != 0) goto LAB_4012b640;
  iStack_8c = param_6 + iStack_8c;
  memw();
  iVar5 = FUN_4013935c(puVar6,puVar4 + uVar2,iStack_8c);
  if (iVar5 != 0) goto LAB_4012b640;
  iVar3 = FUN_4013937c(puVar6,puVar4);
  iVar5 = iVar3;
  if (iVar3 != 0) goto LAB_4012b640;
  param_4 = 0;
  do {
    iVar5 = iVar3;
    param_6 = param_7;
    if (param_4 < param_8) goto LAB_4012b67a;
LAB_4012b640:
    do {
      FUN_40138f78(auStack_70);
      if (puVar4 != (undefined1 *)0x0) {
        FUN_4013ae54(puVar4,iStack_84);
      }
      FUN_4013ae54(local_64,0x40);
      FUN_4013ae44(puVar4);
      iVar3 = iVar5;
LAB_4012b660:
      puVar4 = puStack_24;
      puVar6 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return iVar3;
      }
      (*(code *)&SUB_40082ec4)();
LAB_4012b67a:
      iVar5 = FUN_401393f0(puVar6);
    } while ((((iVar5 != 0) || (iVar5 = FUN_4013935c(puVar6,puVar4,uVar2 + iStack_8c), iVar5 != 0))
             || (iVar5 = FUN_4013937c(puVar6,local_64), iVar5 != 0)) ||
            (((iVar5 = FUN_401393f0(puVar6), iVar5 != 0 ||
              (iVar5 = FUN_4013935c(puVar6,puVar4,uVar2), iVar5 != 0)) ||
             (iVar5 = FUN_4013937c(puVar6,puVar4), iVar5 != 0))));
    param_4 = param_4 + uVar2;
    uVar8 = uVar2;
    if (param_8 < param_4) {
      uVar8 = param_8 % uVar2;
    }
    uVar7 = 0;
    while (uVar7 != uVar8) {
      puVar10 = local_64 + uVar7;
      puVar9 = (undefined1 *)(param_6 + uVar7);
      uVar7 = uVar7 + 1;
      *puVar9 = *puVar10;
      memw();
      memw();
    }
    param_7 = param_6 + uVar2;
  } while( true );
}

