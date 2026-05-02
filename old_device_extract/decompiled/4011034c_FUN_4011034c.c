// Function : FUN_4011034c
// Address  : 0x4011034c
// Size     : 826 bytes


int FUN_4011034c(int param_1,int param_2,uint param_3,uint param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  ushort uVar11;
  undefined4 uVar12;
  char *pcVar13;
  char *pcVar14;
  uint in_t0;
  uint uStack_38;
  int *piStack_2c;
  
  param_3 = param_3 & 0xffff;
  if (param_1 != 0) {
    uVar7 = (uint)(*(ushort *)(param_1 + 0x8e) >> 1);
    uVar2 = (uint)*(ushort *)(param_1 + 0x5e);
    uVar7 = (uVar7 < uVar2) * uVar7 + (uVar7 >= uVar2) * uVar2;
    if (uVar7 == 0) {
      uVar7 = uVar2;
    }
    if (param_2 != 0) {
      if ((*(int *)(param_1 + 0x3c) - 2U < 3) || (*(int *)(param_1 + 0x3c) == 7)) {
        if (param_3 == 0) goto LAB_401103dd;
        if ((param_3 <= *(ushort *)(param_1 + 0x90)) && (*(ushort *)(param_1 + 0x92) < 0x11)) {
          uVar2 = *(uint *)(param_1 + 0x9c);
          if (*(ushort *)(param_1 + 0x92) == 0) goto LAB_401103c9;
          if (uVar2 != 0) goto LAB_401103dd;
          if (*(int *)(param_1 + 0x98) != 0) goto LAB_401103dd;
          pcVar14 = "id pbuf";
          uVar12 = 0x156;
          pcVar13 = "realloc";
          uVar2 = 0;
          param_3 = in_t0;
LAB_401103c0:
          while( true ) {
            (*(code *)&SUB_40094c54)("lid pcb",uVar12,pcVar13,pcVar14);
            in_t0 = param_3;
LAB_401103c9:
            if ((uVar2 == 0) && (uVar2 = *(uint *)(param_1 + 0x98), uVar2 == 0)) break;
            pcVar14 = "n-empty";
            uVar12 = 0x159;
            pcVar13 = "realloc";
            param_3 = in_t0;
          }
LAB_401103dd:
          uVar11 = *(ushort *)(param_1 + 0x92);
          puVar9 = *(undefined4 **)(param_1 + 0x98);
          piVar10 = puVar9;
          if (puVar9 == (undefined4 *)0x0) {
            uVar2 = (uint)*(ushort *)(param_1 + 0x94);
            uVar3 = 0;
            uVar6 = 0;
            if (uVar2 != 0) {
              pcVar14 = "vs. len";
              uVar12 = 0x24b;
              pcVar13 = "_checks";
              param_3 = in_t0;
              goto LAB_401103c0;
            }
          }
          else {
            do {
              puVar9 = piVar10;
              piVar10 = (int *)*puVar9;
            } while (piVar10 != (undefined4 *)0x0);
            uVar3 = *(byte *)((int)puVar9 + 10) & 1;
            uVar2 = (uint)*(ushort *)(puVar9 + 2) + uVar3 * 4;
            if (uVar7 < uVar2) {
              pcVar14 = "s empty";
              uVar12 = 0x1e6;
              pcVar13 = "_checks";
              memw();
              param_3 = in_t0;
              goto LAB_401103c0;
            }
            uVar2 = (uint)*(ushort *)(param_1 + 0x94);
            if (uVar2 == 0) {
              uVar3 = 0;
              uVar6 = 0;
              goto LAB_401105e8;
            }
            uVar3 = (uVar7 - *(ushort *)(puVar9 + 2)) + uVar3 * -4 & 0xffff;
            if (uVar3 < uVar2) {
              pcVar14 = "o small";
              uVar12 = 0x1f8;
              pcVar13 = "_checks";
              param_3 = in_t0;
              goto LAB_401103c0;
            }
            uVar6 = (uVar2 < param_3) * uVar2 + (uVar2 >= param_3) * param_3;
            uVar3 = (uVar6 < uVar3) * uVar6 + (uVar6 >= uVar3) * uVar3;
            uVar6 = uVar2 - uVar3 & 0xffff;
            piVar10 = puVar9;
            if ((uVar6 != 0) && (param_3 != uVar3)) {
              pcVar14 = ". space";
              uVar12 = 0x200;
              pcVar13 = "_checks";
              uVar2 = uVar6;
              param_3 = in_t0;
              goto LAB_401103c0;
            }
          }
LAB_401105e8:
          uVar2 = uVar6;
          piStack_2c = (int *)0x0;
          memw();
          piVar4 = (int *)0x0;
          for (uStack_38 = uVar3; uStack_38 < param_3; uStack_38 = uStack_38 + uVar6 & 0xffff) {
            uVar2 = param_3 - uStack_38 & 0xffff;
            uVar6 = (uVar2 < uVar7) * uVar2 + (uVar2 >= uVar7) * uVar7;
            memw();
            piVar10 = (int *)FUN_4010bbc4(0x4a,uVar7,0x280);
            if (piVar10 == (int *)0x0) goto LAB_40110504;
            if (*piVar10 != 0) {
              pcVar14 = "s NULL)";
              uVar12 = 0x10b;
              pcVar13 = "segment";
              uVar2 = uVar6;
              param_3 = in_t0;
              goto LAB_401103c0;
            }
            uVar2 = *(ushort *)((int)piVar10 + 10) - uVar6 & 0xffff;
            *(short *)(piVar10 + 2) = (short)uVar6;
            *(short *)((int)piVar10 + 10) = (short)uVar6;
            memw();
            memw();
            (*(code *)&SUB_4008b3d0)(piVar10[1],param_2 + uStack_38,uVar6);
            sVar1 = FUN_40185360(piVar10);
            uVar11 = uVar11 + sVar1;
            if (0x11 < uVar11) {
              memw();
              FUN_4010bb10(piVar10);
LAB_40110504:
              *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 0x80;
              memw();
              if (piVar4 != (int *)0x0) {
                memw();
                FUN_4010ce5c(piVar4);
              }
              if ((*(short *)(param_1 + 0x92) == 0) || (*(int *)(param_1 + 0x9c) != 0))
              goto LAB_40110398;
              piVar10 = (int *)(param_1 + 0x98);
              param_1 = 0xff;
              if (*piVar10 != 0) goto LAB_40110680;
              pcVar14 = "!= NULL";
              uVar12 = 0x328;
              pcVar13 = "_checks";
              uVar2 = 0;
              param_3 = in_t0;
              goto LAB_401103c0;
            }
            memw();
            piVar10 = (int *)FUN_4010ffc8(param_1,piVar10,0,uStack_38 + *(int *)(param_1 + 0x88),0);
            if (piVar10 == (int *)0x0) goto LAB_40110504;
            piVar8 = piVar10;
            if (piVar4 != (int *)0x0) {
              if (piStack_2c == (int *)0x0) {
                pcVar14 = "ed pbuf";
                uVar12 = 0x2ab;
                pcVar13 = "_checks";
                param_3 = in_t0;
                goto LAB_401103c0;
              }
              *piStack_2c = (int)piVar10;
              piVar8 = piVar4;
            }
            piVar4 = piVar8;
            piStack_2c = piVar10;
          }
          if (uVar3 != 0) {
            piVar8 = (int *)puVar9[1];
            while (sVar1 = (short)uVar3, piVar8 != (int *)0x0) {
              *(short *)(piVar8 + 2) = sVar1 + *(short *)(piVar8 + 2);
              memw();
              if (*piVar8 == 0) {
                memw();
                (*(code *)&SUB_4008b3d0)
                          (piVar8[1] + (uint)*(ushort *)((int)piVar8 + 10),param_2,uVar3);
                *(short *)((int)piVar8 + 10) = sVar1 + *(short *)((int)piVar8 + 10);
                memw();
              }
              piVar8 = (int *)*piVar8;
              memw();
            }
            uVar7 = (uint)*(ushort *)(puVar9 + 2);
            *(ushort *)(puVar9 + 2) = sVar1 + *(ushort *)(puVar9 + 2);
          }
          *(short *)(param_1 + 0x94) = (short)uVar2;
          memw();
          if (puVar9 == (undefined4 *)0x0) {
            *(int **)(param_1 + 0x98) = piVar4;
          }
          else {
            *puVar9 = piVar4;
            memw();
          }
          *(uint *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + param_3;
          *(short *)(param_1 + 0x90) = *(short *)(param_1 + 0x90) - (short)param_3;
          *(ushort *)(param_1 + 0x92) = uVar11;
          memw();
          if (((uVar11 == 0) || (*(int *)(param_1 + 0x9c) != 0)) || (*(int *)(param_1 + 0x98) != 0))
          {
            param_1 = 0;
            if (((piVar10 != (undefined4 *)0x0) && (piVar10[3] != 0)) && ((param_4 & 2) == 0)) {
              uVar11 = *(ushort *)(piVar10[3] + 0xc);
              memw();
              uVar7 = FUN_40185288(8);
              param_1 = 0;
              uVar7 = (uint)uVar11 | uVar7 & 0xffff;
              iVar5 = piVar10[3];
              *(char *)(iVar5 + 0xc) = (char)uVar7;
              *(char *)(iVar5 + 0xd) = (char)(uVar7 >> 8);
              memw();
            }
            goto LAB_40110680;
          }
          pcVar14 = "!= NULL";
          uVar12 = 0x313;
          pcVar13 = "_checks";
          memw();
          uVar2 = 0;
          param_1 = 0;
          param_3 = in_t0;
          goto LAB_401103c0;
        }
        *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 0x80;
        memw();
LAB_40110398:
        param_1 = 0xff;
        memw();
      }
      else {
        param_1 = 0xf5;
      }
      goto LAB_40110680;
    }
  }
  param_1 = 0xf0;
LAB_40110680:
  memw();
  return param_1;
}

