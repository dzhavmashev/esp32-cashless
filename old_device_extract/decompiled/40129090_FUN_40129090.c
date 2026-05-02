// Function : FUN_40129090
// Address  : 0x40129090
// Size     : 84 bytes


void FUN_40129090(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < 4) {
    iVar2 = *(int *)(param_1 + 0x44);
    iVar1 = iVar2 + param_2 * 0xc;
    if ((*(byte *)(iVar1 + 0x1fc) & 1) != 0) {
      *(int *)(iVar2 + 500) = *(int *)(iVar2 + 500) - *(int *)(iVar1 + 0x204);
      memw();
      FUN_4013ae54(*(undefined4 *)(iVar1 + 0x200));
      FUN_4013ae44(*(undefined4 *)(iVar1 + 0x200));
      (*(code *)&SUB_4008b530)(iVar2 + param_2 * 0xc + 0x1fc,0,0xc);
    }
  }
  return;
}

