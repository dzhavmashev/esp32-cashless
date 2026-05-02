// Function : FUN_4015a284
// Address  : 0x4015a284
// Size     : 116 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015a284(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_30 [6];
  undefined1 uStack_2a;
  undefined1 uStack_29;
  
  iVar1 = FUN_40187c28(param_1);
  if (iVar1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&PTR_DAT_3f4240a4,0x107);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uStack_29 = 0;
  if (_DAT_3ffc8864 != 0) {
    uStack_29 = *(undefined1 *)(iVar1 + 0x2f9);
  }
  memw();
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
  memw();
  (*(code *)&SUB_4008b3d0)(auStack_30,iVar1 + 4,6);
  uStack_2a = (undefined1)*(undefined2 *)(iVar1 + 0x26);
  memw();
  memw();
  FUN_40147240(0xe,auStack_30,8);
  *(undefined1 *)(iVar1 + 0x24) = 0;
  memw();
  memw();
  return;
}

