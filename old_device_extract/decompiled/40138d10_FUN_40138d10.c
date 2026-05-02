// Function : FUN_40138d10
// Address  : 0x40138d10
// Size     : 221 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40138d10(int param_1,int param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_1a4 [384];
  int iStack_24;
  undefined1 auStack_20 [32];
  
  memw();
  uVar3 = *(uint *)(param_1 + 0x50);
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar2 = uVar3;
  if (param_4 != (undefined1 *)0x0) {
    uVar2 = uVar3 * 3 >> 1;
  }
  iVar1 = -5;
  if (0x100 < param_3) goto LAB_40138d68;
  if (0x180 < uVar2 + param_3) goto LAB_40138d68;
  memw();
  (*(code *)&SUB_4008b530)(auStack_1a4,0);
  iVar1 = (**(code **)(param_1 + 0x5c))(*(undefined4 *)(param_1 + 0x60),auStack_1a4,uVar3);
  if (iVar1 == 0) goto LAB_40138d81;
LAB_40138d66:
  iVar1 = -9;
LAB_40138d68:
  do {
    param_1 = iVar1;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_40138d81:
    uVar2 = *(uint *)(param_1 + 0x50);
    if (param_4 != (undefined1 *)0x0) {
      param_4 = auStack_1a4;
      iVar1 = (**(code **)(param_1 + 0x5c))
                        (*(undefined4 *)(param_1 + 0x60),param_4 + uVar2,uVar2 >> 1);
      if (iVar1 != 0) goto LAB_40138d66;
      uVar2 = uVar2 + (*(uint *)(param_1 + 0x50) >> 1);
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      (*(code *)&SUB_4008b3d0)(auStack_1a4 + uVar2,param_2,param_3);
      uVar2 = uVar2 + param_3;
    }
    iVar1 = FUN_40138c20(param_1,auStack_1a4,uVar2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4c) = 1;
    }
    param_4 = auStack_20;
    memw();
    FUN_4013ae54(auStack_1a4,uVar2);
  } while( true );
}

