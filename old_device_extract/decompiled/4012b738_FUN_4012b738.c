// Function : FUN_4012b738
// Address  : 0x4012b738
// Size     : 652 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012b738(int param_1,int param_2,undefined4 param_3,undefined1 *param_4,int param_5,
                 int param_6,undefined1 *param_7)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined1 *puStack_6c;
  undefined1 *puStack_68;
  int iStack_64;
  undefined1 auStack_44 [12];
  byte local_38 [20];
  undefined1 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  puVar7 = auStack_44;
  memw();
  FUN_40138f64(puVar7);
  iVar1 = (*(code *)&SUB_4008c01c)(param_3);
  iVar1 = param_5 + 0x14 + iVar1;
  memw();
  iVar2 = FUN_4013ae30(1,iVar1);
  puVar3 = param_4;
  puVar5 = (undefined1 *)0xffff8100;
  puStack_68 = param_4;
  if (iVar2 == 0) goto LAB_4012b886;
  puVar3 = (undefined1 *)(*(code *)&SUB_4008c01c)(param_3);
  puStack_6c = (undefined1 *)(iVar2 + 0x14);
  memw();
  (*(code *)&SUB_4008b3d0)(puStack_6c,param_3,puVar3);
  (*(code *)&SUB_4008b3d0)(puVar3 + iVar2 + 0x14,param_4,param_5);
  iVar4 = FUN_40138f28(3);
  puVar5 = (undefined1 *)0xffff9400;
  if (iVar4 == 0) goto LAB_4012b886;
  puVar5 = (undefined1 *)FUN_4013905c(puVar7,iVar4,1);
  if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
  puStack_68 = (undefined1 *)(param_2 + 1U >> 1);
  memw();
  puVar5 = (undefined1 *)FUN_40139270(puVar7,param_1,puStack_68);
  if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
  puVar6 = puVar3 + param_5;
  puVar5 = (undefined1 *)FUN_4013935c(puVar7,puStack_6c,puVar6);
  if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
  puVar3 = (undefined1 *)(iVar2 + 4);
  puVar5 = (undefined1 *)FUN_4013937c(puVar7,puVar3);
  if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
  puVar8 = (undefined1 *)0x0;
  iStack_64 = param_6;
  do {
    if (param_7 <= puVar8) {
      memw();
      FUN_40138f78(puVar7);
      iVar4 = FUN_40138f28(4);
      puVar5 = (undefined1 *)0xffff9400;
      if (iVar4 == 0) goto LAB_4012b886;
      puVar5 = (undefined1 *)FUN_4013905c(puVar7,iVar4,1);
      if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
      puVar5 = (undefined1 *)FUN_40139270(puVar7,param_1 + (param_2 - (int)puStack_68),puStack_68);
      if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
      puVar5 = (undefined1 *)FUN_4013935c(puVar7,puStack_6c,puVar6);
      if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
      puVar8 = (undefined1 *)FUN_4013937c(puVar7,iVar2);
      puVar5 = puVar8;
      if (puVar8 != (undefined1 *)0x0) goto LAB_4012b886;
      puStack_6c = puVar6 + 0x14;
      puVar3 = (undefined1 *)0x0;
      do {
        puVar5 = puVar8;
        if (param_7 <= puVar3) goto LAB_4012b886;
        puVar5 = (undefined1 *)FUN_401393f0(puVar7);
        if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
        puVar5 = (undefined1 *)FUN_4013935c(puVar7,iVar2,puStack_6c);
        if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
        puVar5 = (undefined1 *)FUN_4013937c(puVar7,local_38);
        if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
        puVar5 = (undefined1 *)FUN_401393f0(puVar7);
        if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
        puVar5 = (undefined1 *)FUN_4013935c(puVar7,iVar2,0x14);
        if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
        puVar5 = (undefined1 *)FUN_4013937c(puVar7,iVar2);
        if (puVar5 != (undefined1 *)0x0) goto LAB_4012b886;
        puVar3 = puVar3 + 0x14;
        uVar10 = (uint)param_7 % 0x14;
        if (puVar3 <= param_7) {
          uVar10 = 0x14;
        }
        uVar9 = 0;
        pbVar11 = puVar3 + param_6 + -0x14;
        while (uVar9 != uVar10) {
          pbVar12 = local_38 + uVar9;
          uVar9 = uVar9 + 1;
          *pbVar11 = *pbVar12 ^ *pbVar11;
          memw();
          pbVar11 = pbVar11 + 1;
          memw();
        }
      } while( true );
    }
    while ((((puVar5 = (undefined1 *)FUN_401393f0(), puVar5 != (undefined1 *)0x0 ||
             (puVar5 = (undefined1 *)FUN_4013935c(puVar7,puVar3,puVar6 + 0x10),
             puVar5 != (undefined1 *)0x0)) ||
            (puVar5 = (undefined1 *)FUN_4013937c(puVar7,local_38), puVar5 != (undefined1 *)0x0)) ||
           (((puVar5 = (undefined1 *)FUN_401393f0(puVar7), puVar5 != (undefined1 *)0x0 ||
             (puVar5 = (undefined1 *)FUN_4013935c(puVar7,puVar3,0x10), puVar5 != (undefined1 *)0x0))
            || (puVar5 = (undefined1 *)FUN_4013937c(puVar7,puVar3), puVar5 != (undefined1 *)0x0)))))
    {
LAB_4012b886:
      puVar6 = puVar5;
      memw();
      FUN_40138f78(auStack_44);
      FUN_4013ae54(iVar2,iVar1);
      FUN_4013ae54(local_38,0x14);
      FUN_4013ae44(iVar2);
      puVar8 = puStack_24;
      puVar7 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
    }
    puVar8 = puVar8 + 0x10;
    uVar10 = 0x10;
    if (param_7 < puVar8) {
      uVar10 = (uint)param_7 & 0xf;
    }
    uVar9 = 0;
    while (uVar9 != uVar10) {
      pbVar11 = (byte *)(iStack_64 + uVar9);
      pbVar12 = local_38 + uVar9;
      uVar9 = uVar9 + 1;
      *pbVar11 = *pbVar12;
      memw();
      memw();
    }
    iStack_64 = iStack_64 + 0x10;
    memw();
  } while( true );
}

