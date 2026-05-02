// Function : FUN_40110b90
// Address  : 0x40110b90
// Size     : 117 bytes


void FUN_40110b90(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x6f9,"tcp_rst","lid pcb");
  }
  if (((*(int *)(param_1 + 0x9c) != 0) && ((*(ushort *)(param_1 + 0x46) & 4) == 0)) &&
     (cVar1 = FUN_40110ad4(param_1), cVar1 == '\0')) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x74);
    uVar3 = (uint)*(ushort *)(param_1 + 0x8c);
    uVar2 = (int)((uVar3 < uVar2) * uVar3 + (uVar3 >= uVar2) * uVar2) >> 1;
    uVar3 = (uint)*(ushort *)(param_1 + 0x5e) * 2;
    *(short *)(param_1 + 0x76) = (short)uVar2;
    memw();
    if (uVar2 < uVar3) {
      *(short *)(param_1 + 0x76) = (short)uVar3;
      memw();
    }
    *(ushort *)(param_1 + 0x74) = *(ushort *)(param_1 + 0x5e) * 3 + *(short *)(param_1 + 0x76);
    memw();
    *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 4;
    *(undefined2 *)(param_1 + 0x5c) = 0;
    memw();
  }
  memw();
  return;
}

