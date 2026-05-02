// Function : FUN_401001fc
// Address  : 0x401001fc
// Size     : 104 bytes


int FUN_401001fc(uint param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (2 < param_1) {
    (*(code *)&SUB_40094c54)("nts/vfs/vfs_uart.c",0xca," fd < 3",&DAT_3f40e38c);
  }
  pcVar3 = param_2 + param_3;
  iVar2 = *(int *)(&DAT_3f40e4e8 + param_1 * 4);
  (*(code *)&SUB_40086470)(iVar2 + 0xc);
  for (; param_2 != pcVar3; param_2 = param_2 + 1) {
    cVar1 = *param_2;
    if (((cVar1 != '\n') || (*(int *)(iVar2 + 0x14) == 2)) ||
       ((**(code **)(iVar2 + 0x1c))(param_1,0xd), *(int *)(iVar2 + 0x14) != 1)) {
      (**(code **)(iVar2 + 0x1c))(param_1,cVar1);
    }
  }
  (*(code *)&SUB_400864b0)(iVar2 + 0xc);
  return param_3;
}

