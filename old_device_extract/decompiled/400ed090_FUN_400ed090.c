// Function : FUN_400ed090
// Address  : 0x400ed090
// Size     : 286 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ed090(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  int in_WindowStart;
  undefined8 uVar11;
  undefined1 local_40 [24];
  int iStack_28;
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  iStack_28 = 0;
  puVar3 = local_40;
  if ((*(char *)(param_2 + 1) == '\x01') &&
     (puVar3 = local_40, puVar4 = (undefined4 *)local_40, param_3 != (undefined4 *)0x0))
  goto LAB_400ed0d9;
  do {
    FUN_400f0d4c(param_1,param_4);
    while( true ) {
      param_3 = puStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
      param_4 = &DAT_3ffc5708;
      puVar4 = (undefined4 *)puVar3;
LAB_400ed0d9:
      uVar5 = FUN_400f9a18(*param_2,param_3);
      if (uVar5 != 0) {
        uVar11 = func_0x40085c04();
        uVar6 = (*(code *)&SUB_4000cff8)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),1000,0);
        uVar7 = FUN_401847ec(&DAT_3f409974);
        uVar10 = _DAT_3ffbdb9c;
        if (0x1100 < (int)uVar5) {
          uVar10 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar5 & 0xffffeeff) * 4);
        }
        pcVar9 = "%s %s\r\n";
        *puVar4 = uVar10;
        uVar10 = 0x1e3;
        goto LAB_400ed12a;
      }
      iVar1 = (uint)(in_WindowStart == 0) * (int)puVar4;
      iVar2 = (uint)(in_WindowStart != 0) * ((int)puVar4 - (iStack_28 + 0xfU & 0xfffffff0));
      puVar3 = (undefined1 *)(iVar1 + iVar2);
      puVar4 = (undefined4 *)(iVar1 + iVar2);
      iVar8 = iVar1 + iVar2 + 0x10;
      uVar5 = FUN_400f9a18(*param_2,param_3,iVar8,&iStack_28);
      if (uVar5 != 0) break;
      FUN_400f0be8(param_1,iVar8);
    }
    uVar11 = func_0x40085c04();
    uVar6 = (*(code *)&SUB_4000cff8)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),1000,0);
    uVar7 = FUN_401847ec(&DAT_3f409974);
    uVar10 = _DAT_3ffbdb9c;
    if (0x1100 < (int)uVar5) {
      uVar10 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar5 & 0xffffeeff) * 4);
    }
    *(undefined4 *)(iVar1 + iVar2) = uVar10;
    uVar10 = 0x1ea;
    pcVar9 = " < %u\r\n";
LAB_400ed12a:
    FUN_4012105c(pcVar9,uVar6,uVar7,uVar10,"sLength",param_3);
    puVar3 = (undefined1 *)puVar4;
  } while( true );
}

