// Function : FUN_40152298
// Address  : 0x40152298
// Size     : 282 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40152298(int *param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int aiStack_40 [4];
  int *piStack_30;
  
  if ((param_1 != (int *)0x0) && (iVar5 = *param_1, iVar5 != 0)) {
    piStack_30 = aiStack_40;
    memw();
    FUN_4014eb04(_DAT_3ffc8800 != iVar5,piStack_30);
    iVar6 = *(int *)(*(int *)(param_2 + 4) + 4);
    if (*(int *)(iVar5 + 0x14c) == 0) {
      piVar7 = param_1 + 1;
      memw();
      piVar8 = piVar7;
    }
    else {
      piVar7 = param_1 + 1;
      piVar8 = piStack_30;
      if (param_1 == *(int **)(iVar5 + 0xec)) {
        piVar7 = (int *)(iVar5 + 0x9c);
      }
    }
    memw();
    FUN_40151c80(param_1,param_2,param_3,0x10,piStack_30,piVar7,piVar8);
    if ((**(uint **)(param_2 + 0x2c) & 1) != 0) {
      *(byte *)(iVar6 + 1) = *(byte *)(iVar6 + 1) | 0x40;
      memw();
      if ((*param_1 == _DAT_3ffc8800) && (_DAT_3ffc89f4 != 0)) {
        memw();
        FUN_401521f8(param_1,param_2);
      }
    }
    puVar3 = *(uint **)(param_2 + 4);
    memw();
    uVar1 = *(ushort *)(param_2 + 0x16);
    uVar2 = *(ushort *)(param_2 + 0x14);
    memw();
    *puVar3 = *puVar3 | 0x80000000;
    memw();
    memw();
    *puVar3 = *puVar3 | 0x40000000;
    memw();
    memw();
    *puVar3 = *puVar3 & 0xdfffffff;
    memw();
    memw();
    *puVar3 = *puVar3 & 0xff000fff | ((uint)uVar1 + (uint)uVar2 & 0xfff) << 0xc;
    memw();
    iVar5 = FUN_40187c04();
    if (iVar5 == 0) {
      *(undefined4 *)(param_2 + 0x28) = 0;
      *_DAT_3ffc8998 = param_2;
      _DAT_3ffc8998 = (int *)(param_2 + 0x28);
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_4015fb20(param_2);
    }
    memw();
    return uVar4;
  }
  FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0x520);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

