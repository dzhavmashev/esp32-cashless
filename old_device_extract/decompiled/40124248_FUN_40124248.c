// Function : FUN_40124248
// Address  : 0x40124248
// Size     : 67 bytes


int FUN_40124248(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_4018514c(*(undefined4 *)(param_1 + 0x10));
  iVar2 = FUN_4015a608(uVar1,"pansion",*(int *)(param_2 + 0x18),
                       param_2 + *(int *)(param_2 + 0x18) * 0x20 + 0x48,
                       *(undefined4 *)(param_2 + 0x14));
  iVar2 = iVar2 >> 0x1f;
  if ((*(int *)(param_1 + 0x44) != 0) &&
     (iVar3 = FUN_4015a608(7,"pansion",*(int *)(param_2 + 0xf4),
                           param_2 + (*(int *)(param_2 + 0xf4) + 9) * 0x10 + 4,0x10), iVar3 < 0)) {
    iVar2 = -1;
  }
  return iVar2;
}

