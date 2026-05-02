// Function : FUN_401659b8
// Address  : 0x401659b8
// Size     : 251 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401659b8(undefined4 param_1,undefined4 param_2,short param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  
  puVar3 = _DAT_3ffc06fc;
  if (param_3 == 1) {
    piVar9 = (int *)_DAT_3ffc06fc[1];
    uVar4 = FUN_4018b754(piVar9);
    uVar8 = uVar4 & 0xffff;
    if ((uVar8 != 0) && ((DAT_3ffc072c != '\x01' || (-1 < *piVar9)))) {
      puVar6 = (undefined1 *)((int)piVar9 + (uVar4 & 0xffff) + 0x18);
      iVar7 = FUN_40165300(piVar9 + 6,puVar6);
      if (iVar7 == 1) {
        uVar1 = *(undefined1 *)((int)piVar9 + 0x19);
        *puVar6 = (char)piVar9[6];
        memw();
        uVar2 = *(undefined1 *)((int)piVar9 + 0x1a);
        puVar6[1] = uVar1;
        memw();
        uVar1 = *(undefined1 *)((int)piVar9 + 0x1b);
        puVar6[2] = uVar2;
        puVar6[3] = uVar1;
        memw();
        memw();
      }
      else if (iVar7 == 2) {
        uVar8 = 0;
      }
      memw();
      iVar5 = (**(code **)(_DAT_3ffc1a34 + 0x16c))((*puVar3 >> 0xc & 0xfff) - uVar8);
      if (iVar5 != 0) {
        (*(code *)&SUB_4008b3d0)(iVar5,puVar3[1],0x18);
        memw();
        (*(code *)&SUB_4008b3d0)
                  (iVar5 + 0x18,puVar3[1] + uVar8 + 0x18,((*puVar3 >> 0xc & 0xfff) - uVar8) + -0x18)
        ;
        FUN_40165378(puVar3[1] + 0x18,uVar8,iVar5,iVar5 + 0x1c,*(uint *)(iVar5 + 0x18) & 0xfff,iVar7
                    );
        (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar5);
      }
    }
  }
  else {
    FUN_40147fe4(6,0x20,2,0x3f43713e);
  }
  return 1;
}

