// Function : FUN_4013183c
// Address  : 0x4013183c
// Size     : 68 bytes


int FUN_4013183c(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)((param_3 & 3) != 0) + (param_3 >> 2);
  iVar1 = FUN_401315c4(param_1,iVar2);
  if (((param_3 != 0) && (iVar1 == 0)) &&
     ((*(code *)&SUB_4008b3d0)(*(int *)(param_1 + 8) + (iVar2 * 4 - param_3),param_2,param_3),
     iVar2 != 0)) {
    FUN_401314a0(*(undefined4 *)(param_1 + 8),iVar2);
  }
  return iVar1;
}

