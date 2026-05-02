// Function : FUN_40146e58
// Address  : 0x40146e58
// Size     : 106 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146e58(uint param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_401460c8();
  uVar3 = 0x3001;
  if (((iVar1 != 0) && (uVar3 = 0x3004, param_1 < 2)) && (uVar3 = 0x102, param_2 != 0)) {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0xa4);
    uVar3 = 0x101;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0xb;
      memw();
      puVar2[8] = (char)param_1;
      *(undefined4 **)(puVar2 + 4) = &DAT_4014fbf0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      memw();
      *(undefined4 *)(puVar2 + 0xc) = 0;
      memw();
      (*(code *)&SUB_4008b3d0)(puVar2 + 0x14,param_2,0x8c);
      uVar3 = FUN_40150444(puVar2);
    }
  }
  return uVar3;
}

