// Function : FUN_40133c98
// Address  : 0x40133c98
// Size     : 205 bytes


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40133c98(int param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 auStack_1a4 [384];
  uint uStack_24;
  undefined1 auStack_20 [32];
  
  memw();
  uVar3 = *(uint *)(param_1 + 0x18);
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar1 = -0x38;
  if (0x180 < uVar3) goto LAB_40133ce9;
  if ((undefined1 *)(0x180 - uVar3) < param_4) goto LAB_40133ce9;
  if ((0x180 - (int)param_4) - uVar3 < param_3) goto LAB_40133ce9;
  memw();
  (*(code *)&SUB_4008b530)(auStack_1a4,0);
  iVar1 = (**(code **)(param_1 + 0x44))(*(undefined4 *)(param_1 + 0x48),auStack_1a4,uVar3);
  if (iVar1 == 0) goto LAB_40133d01;
LAB_40133ce6:
  iVar1 = -0x34;
LAB_40133ce9:
  do {
    param_3 = uStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return iVar1;
    }
    (*(code *)&SUB_40082ec4)();
LAB_40133d01:
    puVar2 = *(undefined1 **)(param_1 + 0x18);
    if (param_4 != (undefined1 *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x44))
                        (*(undefined4 *)(param_1 + 0x48),auStack_1a4 + (int)puVar2,param_4);
      if (iVar1 != 0) goto LAB_40133ce6;
      puVar2 = puVar2 + (int)param_4;
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      (*(code *)&SUB_4008b3d0)(auStack_1a4 + (int)puVar2,param_2,param_3);
      puVar2 = puVar2 + param_3;
    }
    iVar1 = FUN_401339d4(auStack_1a4,auStack_1a4,puVar2);
    if ((iVar1 == 0) && (iVar1 = FUN_40133bc0(param_1,auStack_1a4), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
    param_4 = auStack_20;
    memw();
    FUN_4013ae54(auStack_1a4,0x180);
  } while( true );
}

