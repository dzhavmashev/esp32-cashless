// Function : FUN_401174f8
// Address  : 0x401174f8
// Size     : 339 bytes


uint * FUN_401174f8(int param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte extraout_var;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  byte bVar11;
  bool bVar12;
  uint *puVar13;
  
  uVar7 = *param_2;
  bVar2 = 0xe;
  if ((uVar7 & 0xe0) != 0x20) {
    bVar2 = 2;
    if ((uVar7 & 0xc0ff) != 0x80fe) {
      if (uVar7 == 0) {
        bVar2 = 0xe;
        if (((param_2[1] == 0) && (param_2[2] == 0)) && (param_2[3] == 0x1000000)) {
          bVar2 = 2;
        }
      }
      else {
        bVar2 = 8;
        if ((uVar7 & 0xfe) != 0xfc) {
          if ((uVar7 & 0xff) == 0xff) {
            FUN_40109eec();
            bVar2 = extraout_var & 0xf;
          }
          else {
            bVar2 = 0xe;
            if ((uVar7 & 0xc0ff) == 0xc0fe) {
              bVar2 = 5;
            }
          }
        }
      }
    }
  }
  iVar9 = 0;
  puVar10 = (uint *)(param_1 + 0x4c);
  uVar7 = 0;
  puVar13 = (uint *)0x0;
  bVar11 = 0;
  bVar12 = false;
  do {
    bVar1 = *(byte *)(param_1 + iVar9 + 0x94);
    if ((bVar1 & 0x10) == 0) {
LAB_40117634:
      puVar3 = puVar13;
      uVar8 = uVar7;
      bVar5 = bVar11;
      bVar6 = bVar12;
    }
    else {
      uVar4 = *puVar10;
      bVar5 = 0xe;
      if ((uVar4 & 0xe0) != 0x20) {
        bVar5 = 2;
        if ((((uVar4 & 0xc0ff) != 0x80fe) && (bVar5 = 8, (uVar4 & 0xfe) != 0xfc)) &&
           (bVar5 = 0xf, (uVar4 & 0xc0ff) == 0xc0fe)) {
          bVar5 = 5;
        }
      }
      bVar6 = bVar1 == 0x30;
      uVar8 = 0;
      if (((uVar4 == *param_2) && (puVar10[1] == param_2[1])) &&
         (uVar8 = 1, puVar10[2] == param_2[2])) {
        if (puVar10[3] == param_2[3]) {
          puVar3 = (uint *)(param_1 + iVar9 * 0x18 + 0x4c);
          break;
        }
        uVar8 = 1;
      }
      puVar3 = puVar10;
      if (((puVar13 != (uint *)0x0) &&
          (((bVar11 <= bVar5 || (bVar5 < bVar2)) &&
           ((byte)((bVar2 < bVar5) * bVar2 + (bVar2 >= bVar5) * bVar5) <= bVar11)))) &&
         ((bVar5 != bVar11 || ((bVar6 <= bVar12 && ((bVar6 != bVar12 || (uVar8 <= uVar7))))))))
      goto LAB_40117634;
    }
    uVar7 = uVar8;
    iVar9 = iVar9 + 1;
    puVar10 = puVar10 + 6;
    puVar13 = puVar3;
    bVar11 = bVar5;
    bVar12 = bVar6;
  } while (iVar9 != 3);
  memw();
  return puVar3;
}

